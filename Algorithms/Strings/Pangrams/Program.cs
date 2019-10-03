using System;
using System.Collections.Generic;

/*
    https://www.hackerrank.com/challenges/pangrams/problem
*/
namespace Pangrams
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();

            string solution = Solve(s);

            Console.WriteLine(solution);
        }

        static string Solve(string s) {
            var hashSet = new HashSet<int>();

            for (int i = 0; i <= 'z' - 'a'; i++) {
                hashSet.Add('a' + i);
            }

            for (int i = 0; i < s.Length; i++) {
                var currentAsciiLowerCase = ToLowerCase(s[i]);

                if (hashSet.Contains(currentAsciiLowerCase)) {
                    hashSet.Remove(currentAsciiLowerCase);
                }

                if (hashSet.Count == 0) {
                    return "pangram";
                }
            }

            return "not pangram";
        }

        static int ToLowerCase(char c) {
            if (c >= 'A' && c <= 'Z') {
                var difference = (int)c - 'A';

                return 'a' + difference;
            }

            return (int)c;
        }
    }
}
