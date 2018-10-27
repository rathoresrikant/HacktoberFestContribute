class BinaryRepresentationOfInteger
{ 
    static void convertDecimaltoBinary(int number) 
    { 
        if(number > 1)
        {
            convertDecimaltoBinary(number>>1);
        }
        System.out.print("" + number%2);
    } 
      
    public static void main(String args[]) 
    { 
        BinaryRepresentationOfInteger.convertDecimaltoBinary(5);
        System.out.println();
    } 
} 
