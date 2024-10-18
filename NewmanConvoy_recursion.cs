using System;

public class NewConvSeq
{
    // Using Recursion
    static int newmanConvoy(int n)
    {
        if (n == 1 || n == 2) // Base case
            return 1;

        // Correct recursive calls for Newman-Conway sequence
        return newmanConvoy(newmanConvoy(n - 1)) + newmanConvoy(n - newmanConvoy(n - 1));
    }

    public static void Main()
    {
        Console.WriteLine("Enter a position in the Newman-Conway sequence:");
        string val = Console.ReadLine();

        // Input validation
        if (int.TryParse(val, out int num) && num > 0)
        {
            Console.WriteLine($"Newman-Conway Number corresponding to position {num} is: {newmanConvoy(num)}");
        }
        else
        {
            Console.WriteLine("Please enter a valid positive integer.");
        }
    }
}
