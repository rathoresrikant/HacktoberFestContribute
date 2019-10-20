import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;



public class LRC {

    public static void main(String[] args) throws IOException {
        File file = new File("input.txt");
        if(file.exists()){
            FileReader fr= new FileReader(file);
            String fileContain;
            try (BufferedReader br =  new BufferedReader(fr)) {
                fileContain = br.readLine();
                System.out.println("Your file contains: "+ fileContain);
                br.close();
            }
            fr.close();
        
            String finMes = convMes(fileContain);
            System.out.println("Message without parity bit: "+finMes);
            System.out.println("");
            String[] tokens=finMes.split(" ");
            String lrc = "";
            int col,cnt=0;
            Scanner sc = new Scanner(System.in);
            System.out.print("Input 1 for odd parity and 0 for even parity: ");
            int urWish = sc.nextInt();
            if(urWish==0){
                for(col=0;col<7;col++){
                    for (String token : tokens) {
                        if (token.charAt(col) == '1') {
                            cnt++;
                        }
                    }
                    if(cnt%2==0){
                        lrc+="0";
                    }
                    else{
                        lrc+="1";
                    }
                    cnt=0;
                }
            }
            else{
                for(col=0;col<7;col++){
                    for (String token : tokens) {
                        if (token.charAt(col) == '1') {
                            cnt++;
                        }
                    }
                    if(cnt%2==0){
                        lrc+="1";
                    }
                    else{
                        lrc+="0";
                    }
                    cnt=0;
                }
            }
            finMes = String.join(" ", tokens);
//            System.out.println("fin: "+finMes);
            finMes =finMes + " " + lrc;
            System.out.println("Message to be transmitted: "+ finMes);
            
            FileWriter fw = new FileWriter("lrcOutput.txt",false);
            //BufferedWriter br =new BufferedWriter(fw);
            fw.write(finMes);
            fw.close();
        }
        else{
            System.out.println("File doesn't exist");
        }
        
    }
        
    public static String convMes(String s){
        String mes="";
        
        for(int i=0;i<s.length();i++){
            int asciee=(int)s.charAt(i);
            mes = mes + binarycon(asciee) + " ";
        }
        
        return mes;
    }
    public static String binarycon(int value){
        int a;
        String bin="";
        String bin1="";
        while(value>0){
            a=value%2;
            bin=bin+""+a;
            value/=2;
        }
        for(int i=bin.length()-1;i>=0;i--){
            bin1+=bin.charAt(i);
        }
        while(bin1.length()<7){
            bin1='0'+bin1;
        }
        return bin1;
    }   
}
