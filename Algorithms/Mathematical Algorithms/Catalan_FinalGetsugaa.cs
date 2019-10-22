// A recursive C# program to find
// nth catalan number
using System;

class Catalan {

    static int catalan(int n) {
        int ans = 0;

        if (n <= 1) {
            return 1;
        }
        for (int i = 0; i < n; i++)
        {
            ans += catalan(i) * catalan(n - i - 1);
        }
        return ans;
    }

    public static void Main()
    {
      string val;
      val = Console.ReadLine();

      int num = Convert.ToInt32(val);
      Console.WriteLine("Catalan Number Corresponding to entered position is:");
      Console.Write(catalan(num));
    }
}
