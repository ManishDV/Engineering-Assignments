import java.io.*;
import java.util.Random;
import java.io.FileWriter;
    
public class GenerateAndSave {
    public static void main(String[] args) throws Exception {
        FileWriter writer = new FileWriter("input.txt");
        double arr[] = new double[10000001];
        int len = arr.length;
        Random r = new Random(); 
        

        for (int i = 0; i < len; i++) {
            writer.write(r.nextDouble(100) + "\t"+ "");
        }
        
        writer.close();
    

        System.out.println("File input.txt has been created!");
    }
}