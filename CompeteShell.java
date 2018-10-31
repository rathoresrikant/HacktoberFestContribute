import java.util.Scanner;
public class Colony 
{
    public static int[] cellCompete(int[] cell, int day) 
    {
        int b[]=new int[cell.length];
       
        
        for(int i=1;i<=day;i++)
        {
        for(int t=0;t<cell.length;t++)
        {
            if(t==0)
                b[t]=0^cell[t+1];
                else if(t==cell.length-1)
                b[t]=cell[t-1]^0;
                else
                b[t]=cell[t-1]^cell[t+1];
            }
            System.arraycopy(b,0,cell,0,cell.length);
        }
        return b;
       
    }   
    public static void main(String[] args)
    {

        int a[]=new int[8];
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<8;i++)
        {
            a[i]=sc.nextInt();
        }
        
        int day;
        day=sc.nextInt();
        int m[];
        m = cellCompete(a, day);
        for(int i=0; i<8; i++) 
        {
            System.out.println(m[i]);
        }
    }
}
