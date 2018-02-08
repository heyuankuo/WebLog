#include "TriangleDemo.h"


struct VertexPos
{
    XMFLOAT3 pos;
};

TriangleDemo::TriangleDemo() 
: m_pInputLayout(0), m_pVertexBuffer(0)
{
    XMMATRIX I = XMMatrixIdentity();
    XMStoreFloat4x4(&m_world, I);
    XMStoreFloat4x4(&m_view, I);
    XMStoreFloat4x4(&m_proj, I);
}


TriangleDemo::~TriangleDemo()
{
}

void TriangleDemo::UnLoadContent()
{
    if (m_pVertexBuffer)
        m_pVertexBuffer->Release();
    if (m_pInputLayout)
        m_pInputLayout->Release();
    if (m_pFx)
        m_pFx->Release();
    m_pVertexBuffer = 0;
    m_pInputLayout = 0;
    m_pFx = 0;
}

bool TriangleDemo::LoadContent()
{
    HRESULT result;
    VertexPos vertices[] =
    {
        XMFLOAT3(0.5f, 0.5f, 0.5f),
        XMFLOAT3(0.5f, -0.5f, 0.5f),
        XMFLOAT3(-0.5f, -0.5f, 0.5f)
    };

    D3D11_BUFFER_DESC vertexDesc;
    ZeroMemory(&vertexDesc, sizeof vertexDesc));
    vertexDesc.Usage = D3D11_USAGE_DEFAULT;
    vertexDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    vertexDesc.ByteWidth = sizeof(VertexPos)* 3;

    D3D11_SUBRESOURCE_DATA resourceData;
    ZeroMemory(&resourceData, sizeof(resourceData));
    resourceData.pSysMem = vertices;

    result = m_pd3dDevice->CreateBuffer(&vertexDesc, &resourceData, &m_pVertexBuffer);
    if (FAILED(result))
    {
        return false;
    }


    DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined _DEBUG || defined DEBUG
    shaderFlags = D3DCOMPILE_DEBUG;
#endif

    ID3D10Blob *compiledShader = 0;
    ID3D10Blob *compilationMsgs = 0;
    result = D3DX11CompileFromFile("SolidColor.fx", 0, 0, 0, "fx_5_0", shaderFlags,
        0, 0, &compiledShader, &compilationMsgs, 0);
    if (compilationMsgs != 0)
    {
        MessageBox(0, (char*)compilationMsgs->GetBufferPointer(), 0, 0);
        compilationMsgs->Release();
        compilationMsgs = 0;
    }
    if (FAILED(result))
    {
        MessageBox(0, "载入着色器错误", 0, 0);
        return false;
    }

    result = D3DX11CreateEffectFromMemory(compiledShader->GetBufferPointer(), compiledShader->GetBufferSize(),
        0, m_pd3dDevice, &m_pFx);
    compiledShader->Release();
    if (FAILED(result))
    {
        MessageBox(0, "载入着色器失败", 0, 0);
        return false;
    }
    m_pTechnique = m_pFx->GetTechniqueByName("ColorTech");
    m_pFxWorldViewProj = m_pFx->GetVariableByName("gWorldViewProj")->AsMatrix();
    
    D3D11_INPUT_ELEMENT_DESC solidColorLayout[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }
    };
    UINT numLayoutElements = ARRAYSIZE(solidColorLayout);
    D3DX11_PASS_DESC passDesc;
    m_pTechnique->GetPassByIndex(0)->GetDesc(&passDesc);

    result = m_pd3dDevice->CreateInputLayout(solidColorLayout, numLayoutElements, passDesc.pIAInputSignature,
        passDesc.IAInputSignatureSize, &m_pInputLayout);
    
    return true;
}



void TriangleDemo::Update(float dt)
{

}

void TriangleDemo::Render()
{
    if (m_pImmediateContext == 0)
        return;
    //清除渲染目标视图
    float clearColor[4] = { 0.5f, 0.5f, 0.5f, 1.0f };//背景颜色
    m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, clearColor);

    UINT stride = sizeof(VertexPos);
    UINT offset = 0;
    //设置数据信息格式控制信息
    m_pImmediateContext->IASetInputLayout(m_pInputLayout);
    //设置要绘制的几何体信息
    m_pImmediateContext->IASetVertexBuffers(0,1,&m_pVertexBuffer,&stride,&offset);
    //指明如何绘制三角形
    m_pImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    //设置常量 
    XMMATRIX world = XMLoadFloat4x4(&m_world);
    XMMATRIX view = XMLoadFloat4x4(&m_view);
    XMMATRIX proj = XMLoadFloat4x4(&m_proj);
    XMMATRIX worldViewProj = world*view*proj;
    m_pFxWorldViewProj->SetMatrix(reinterpret_cast<float*>(&worldViewProj));

    D3DX11_TECHNIQUE_DESC techDesc;
    m_pTechnique->GetDesc(&techDesc);
    for (UINT i = 0; i < techDesc.Passes; ++i)
    {
        m_pTechnique->GetPassByIndex(i)->Apply(0, m_pImmediateContext);
        m_pImmediateContext->Draw(3, 0);
    }
    //马上输出
    m_pSwapChain->Present(0, 0);
}