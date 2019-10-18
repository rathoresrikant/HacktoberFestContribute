package src.java;

public class ReverseString {
    int size;
    char[] a;
    int top;
    ReverseString(int n){
        top = -1;
        size = n;
        a= new char[n];
    }
    boolean isEmpty(){
        return top<0;
    }
    boolean push(char c){
        if(top>=size){
            System.out.println("Stack Overflow");
            return false;
        }
        else{
            a[++top] = c;
            return true;
        }
    }
    char pop(){
        if(top<0){
            System.out.println("Stack Underflow");
            return 0;
        }
        else{
            char c = a[top--];
            return c;
        }
    }
    static void reverse(StringBuffer str){
        int n = str.length();
        ReverseString stackStringReverse = new ReverseString(n);
        for(int i = 0 ;i<n;i++){
            stackStringReverse.push(str.charAt(i));
        }
        for(int i = 0 ;i<n;i++){
            char c = stackStringReverse.pop();
            str.setCharAt(i,c);
        }
    }
    public static void main(String[] args){
        StringBuffer str =  new StringBuffer("Harishma 98343hj:'3");
        reverse(str);
        System.out.println("The reversed string is "+str);
    }
}
