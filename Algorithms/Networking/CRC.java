import java.io.*;
import java.util.Scanner;
import java.util.Vector;

public class CRC {
    public static void main(String[] args) throws FileNotFoundException,IOException {
        Scanner sc = new Scanner(System.in);
        String string1 = new Scanner(new File("input.txt")).useDelimiter("\\A").next();
        System.out.println(""+string1);
        String string = new String();
        String str[] = new String[7];
        File f = new File("crcOutput.txt");
        if (!f.exists())
            f.createNewFile();
        FileWriter f2 = new FileWriter("crcOutput.txt", false);
        for(int i=0;i<7;i++) {
            str[i] = new String();
        }
        for(int i=0;i<string1.length();i++) {
            string=getBinary(string1.charAt(i));
            //System.out.println(""+string);
            f2.write(string);
        }
        f2.close();
        string1 = new Scanner(new File("crcOutput.txt")).next();
        Vector<Character> Arr = new Vector<>();
        System.out.print("Enter key(Generator) : ");
        String key = sc.next();
        for(int i=0;i<key.length()-1;i++)
            string1+='0';
        for(int i=0;i<string1.length();i++)
            Arr.add(i,string1.charAt(i));
        while(Arr.size()>(key.length()-1)){
            if(Arr.elementAt(0)=='0'){
                Arr.removeElementAt(0);
                continue;
            }
            for(int j=0;j<key.length();j++){
                if(key.charAt(j)==Arr.elementAt(j)) {
                    Arr.removeElementAt(j);
                    Arr.insertElementAt('0', j);
                }
                else {
                    Arr.removeElementAt(j);
                    Arr.insertElementAt('1', j);
                }
            }
        }
        f2 = new FileWriter("crcOutput.txt", true);
        for(int i=0;i<Arr.size();i++)
            f2.write(Arr.elementAt(i));
        f2.close();
    }
    static String getBinary(int number){
        int temp=number;
        String binary = new String();
        while(number!=0){
            binary = (number%2)+binary;
            number /= 2;
        }
        number = temp;
        while(binary.length()!=7)
            binary = '0' + binary;
        return binary;
    }
}
