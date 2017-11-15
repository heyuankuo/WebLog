package excelExchange;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Iterator;
import java.util.Vector;

import org.apache.poi.hslf.HSLFSlideShow;
import org.apache.poi.hslf.usermodel.SlideShow;
import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFObjectData;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.hwpf.HWPFDocument;
import org.apache.poi.poifs.filesystem.DirectoryNode;
//import org.apache.poi.h;
import org.apache.poi.poifs.filesystem.*;

public class ReadEmbeddedObject {

    public static void main(String[] args) throws IOException {

        String fileName = "C:\\Mayur\\NewsLetter\\files\\projectInfo.xls";
        //Vector dataHolder = 
        ReadCSV(fileName);
    }

    public static void ReadCSV(String fileName) throws IOException{
        Vector cellVectorHolder = new Vector();
        FileInputStream myInput = new FileInputStream(fileName);

        // myFileSystem=fs
        //myWorkBook=workbook
		
        POIFSFileSystem fs = new POIFSFileSystem(myInput);
        HSSFWorkbook workbook = new HSSFWorkbook(fs);

          for (HSSFObjectData obj : workbook.getAllEmbeddedObjects()) {
            //the OLE2 Class Name of the object
            System.out.println("Objects : "+ obj.getOLE2ClassName()+ "   2 .");
            String oleName = obj.getOLE2ClassName();


            if (oleName.equals("Worksheet")) {
                System.out.println("Worksheet");
                DirectoryNode dn = (DirectoryNode) obj.getDirectory();
                HSSFWorkbook embeddedWorkbook = new HSSFWorkbook(dn, fs, false);
                System.out.println(oleName+": " + embeddedWorkbook.getNumberOfSheets());
                System.out.println("Information :--- ");
                System.out.println(" name " + embeddedWorkbook.getSheetName(0));
                //System.out.println(entry.getName() + ": " + embeddedWorkbook.getNumberOfSheets());
            } else if (oleName.equals("Document")) {


                System.out.println("Document");
                DirectoryNode dn = (DirectoryNode) obj.getDirectory();
                HWPFDocument embeddedWordDocument = new HWPFDocument(dn,fs);
                System.out.println("Doc : " + embeddedWordDocument.getRange().text());
            }  else if (oleName.equals("Presentation")) {
                System.out.println("Presentation");
                DirectoryNode dn = (DirectoryNode) obj.getDirectory();
                SlideShow embeddedPowerPointDocument = new SlideShow(new HSLFSlideShow(dn, fs));
                //Entry entry = (Entry) entries.next();
                System.out.println(": " + embeddedPowerPointDocument.getSlides().length);
            } else {
                System.out.println("Else part ");
                if(obj.hasDirectoryEntry()){
                    // The DirectoryEntry is a DocumentNode. Examine its entries to find out what it is
                    DirectoryNode dn = (DirectoryNode) obj.getDirectory();
                    for (Iterator entries = dn.getEntries(); entries.hasNext();) {
                        Entry entry = (Entry) entries.next();
                        System.out.println(oleName + "." + entry.getName());
                    }
                } else {
                    // There is no DirectoryEntry
                    // Recover the object's data from the HSSFObjectData instance.
                    byte[] objectData = obj.getObjectData();
                }
            }
        }


    }

}
