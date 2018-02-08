	VertexPos vertices[]  =
    {
        XMFLOAT3(0.5f, 0.5f, 0.5f),
        XMFLOAT3(0.5f, -0.5f, 0.5f),
        XMFLOAT3(-0.5f,-0.5f,0.5f)
    };

    D3D11_BUFFER_DESC vertexDesc;
    ZeroMemory(&vertexDesc, sizeof(vertexDesc));
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
	
	//载入顶点着色器
    ID3DBlob *vsBuffer = 0;
    bool compileResult = CompileD3DShader("SolidColor.fx", "VS_Main", "vs_4_0", &vsBuffer);
    if (!compileResult)
    {
        MessageBox(0, "载入顶点着色器错误", "编译错误", MB_OK);
        return false;
    }

    HRESULT result;
    result = m_pd3dDevice->CreateVertexShader(vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(),
        0, &m_pSolidColorVS);

    if (FAILED(result))
    {
        if (vsBuffer)
        {
            vsBuffer->Release();
        }
        return false;
    }

    D3D11_INPUT_ELEMENT_DESC solidColorLayout[] = 
    {
        {"POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0}
    };

    UINT numLayoutElements = ARRAYSIZE(solidColorLayout);
    result = m_pd3dDevice->CreateInputLayout(solidColorLayout, numLayoutElements, vsBuffer->GetBufferPointer(),
        vsBuffer->GetBufferSize(), &m_pInputLayout);
    vsBuffer->Release();

    if (FAILED(result))
    {
        return false;
    }

    //载入像素着色器
    ID3DBlob *psBuffer = 0;
    compileResult = CompileD3DShader("SolidColor.fx", "PS_Main", "ps_4_0", &psBuffer);
    if (!compileResult)
    {
        MessageBox(0, "像素着色器加载失败", "编译错误", MB_OK);
        return false;
    }

    result = m_pd3dDevice->CreatePixelShader(psBuffer->GetBufferPointer(), psBuffer->GetBufferSize(),
        0, &m_pSolidColorPS);
    psBuffer->Release();
    if (FAILED(result))
    {
        return false;
    }