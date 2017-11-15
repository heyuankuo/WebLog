//创建一个工作簿
        HSSFWorkbook workbook = new HSSFWorkbook();
        //创建一个sheet
        ISheet sheet1 = workbook.CreateSheet("sheet1");
        // 设置列宽,excel列宽每个像素是1/256
        sheet1.SetColumnWidth(0, 18 * 256);
        sheet1.SetColumnWidth(1, 18 * 256);
        IRow rowHeader = sheet1.CreateRow(0);//创建表头行
        rowHeader.CreateCell(0, CellType.STRING).SetCellValue("生产单号");
        rowHeader.CreateCell(1, CellType.STRING).SetCellValue("图片");
        DataTable dt = sqlhelperPro.seachData("SELECT top 3 PRODID,KTL_PIC FROM Long_tmpPIC");
        if (dt.Rows.Count > 0)
        {
            int rowline = 1;//从第二行开始(索引从0开始)
            foreach (DataRow datarow in dt.Rows)
            {
                IRow row = sheet1.CreateRow(rowline);
                //设置行高 ,excel行高度每个像素点是1/20
                row.Height = 80 * 20;
                  //填入生产单号
                row.CreateCell(0, CellType.STRING).SetCellValue(datarow["PRODID"].ToString());
                  //将图片文件读入一个字符串
               byte[] bytes = System.IO.File.ReadAllBytes(datarow["KTL_PIC"].ToString());
               int pictureIdx=workbook.AddPicture(bytes,PictureType.JPEG);
             HSSFPatriarch patriarch = (HSSFPatriarch)sheet1.CreateDrawingPatriarch();
            // 插图片的位置  HSSFClientAnchor（dx1,dy1,dx2,dy2,col1,row1,col2,row2) 后面再作解释
             HSSFClientAnchor anchor = new HSSFClientAnchor(70, 10,0,0, 1,rowline, 2, rowline +1);
            //把图片插到相应的位置
             HSSFPicture pict = (HSSFPicture)patriarch.CreatePicture(anchor, pictureIdx);
                rowline++;
            }
        }
          //把文件保存到d:\aaa.xls，注意扩展名是.xls不要写成.xlsx
         using (Stream stream = File.OpenWrite("d:\aaa.xls"))
        {
            workbook.Write(stream);
        }
//如果要操作.xlsx的excel，引入命名空间  using NPOI.XSSF.UserModel;
// 然后把所有的HSS改为XSS(比喻HSSWorkbook->XSSWorkbook)