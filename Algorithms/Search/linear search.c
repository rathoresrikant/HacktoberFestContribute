#include <stdio.h>
#include <stdlib.h>


    int main()
    {
      int array[1000], sk, x, n;

      printf("Enter number of elements\n");
      scanf("%d", &n);

      printf("Enter %d integer(s)\n", n);

      for (x = 0; x < n; x++)
      scanf("%d", &array[x]);

      printf("Enter a the number you want search\n");
      scanf("%d", &sk);

      for (x = 0; x < n; x++)
      {
        if (array[x] == sk)    /* If required element is found */
        {
          printf("%d is present at location %d.\n", sk, x+1);
          break;
        }
      }
      if (x == n)
        printf("%d isn't present in the array.\n", sk);

      return 0;
    }
