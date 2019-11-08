import java.util.*;
import java.lang.*;
public class PndC{
static int n=8; 
static int full=0;
static int empty=n;
static int in=0,out=0;
static char[] buffer = new char[n];
static void producer(){
Scanner sc = new Scanner(System.in);
System.out.println("Enter the item to produce");
char c = sc.next().charAt(0);
if(full==n)
System.out.println("Buffer is full");
else{
full++;
buffer[in]=c;
empty--;
in=(in+1)%n;
System.out.println("Item produced");
}
}
static char consumer(){
char c ='0';
if(empty==n)
System.out.println("Buffer is empty.. produce first!");
else{
c = buffer[out];
empty++;
full--;
out=(out+1)%n;
}
return c;
}
public static void main(String[] args){
Scanner sc = new Scanner(System.in);
while(true){
System.out.println("Enter the role: 1.Producer\n2.consumer\n3.exit");
int i= sc.nextInt();
switch(i){
case 1:
producer();
break;
case 2:
System.out.println("Item consumed: "+consumer());
break;
case 3:
System.exit(1);
break;
default:
System.out.println("invalid input");
}
}
}
}