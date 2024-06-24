import java.util.*;
import java.lang.*;
public class Dining{
static int n=5;
static int[] state = new int[n];
static void take_fork(int p){
state[p]=1;
if(test(p)){}
else
System.out.println("fork not available");
}
static void put_fork(int p){
int left = (p+n-1)%n;
int right = (p+1)%n;
state[p]=0;
test(left);
test(right);
}
static boolean test(int p){
int left = (p+n-1)%n;
int right = (p+1)%n;
if((state[p]==1)&&(state[left]!=2)&&(state[right]!=2)){
state[p]=2;
System.out.println("Philosopher "+p+"is eating");
return true;
}
else
return false;
} 
public static void main(String[] args){
Scanner in = new Scanner(System.in);
while(true){
System.out.println("Enter the state:\n1.Hungry\n2.Done with eating\n3.exit");
int i = in.nextInt();
System.out.println("Enter the philosopher in that state:");
int p = in.nextInt();
switch(i){
case 1:
take_fork(p);
break;
case 2:
put_fork(p);
break;
case 3:
System.exit(0);
break;
default:
System.out.println("Invalid Input");
break;
}
}
}}