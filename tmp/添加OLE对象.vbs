Sub AddShapes()
	Dim ShpBut As Shape
	On Error Resume Next
	Sheet1.OLEObjects("MyButton").Delete
	Set ShpBut = Sheet1.Shapes.AddOLEObject(ClassType:="Forms.CommandButton.1", Left:=108, Top:=72, Width:=108, Height:=27)
	ShpBut.Name = "MyButton"
	With ActiveWorkbook.VBProject.VBComponents(Sheet1.CodeName).CodeModule
		If .Lines(1, 1) <> "Option Explicit" Then
			.InsertLines 1, "Option Explicit"
		End If
		If .Lines(2, 1) = "Private Sub MyButton_Click()" Then Exit Sub
		.InsertLines 2, "Private Sub MyButton_Click()"
		.InsertLines 3, vbTab & "MsgBox ""这是使用AddOLEObject方法新建的按钮!"""
		.InsertLines 4, "End Sub"
	End With
End Sub
