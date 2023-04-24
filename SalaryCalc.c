#include <stdio.h>
#include <stdlib.h>

int main()
{
    float basic_sal,new_sal,x; //x is the Increment value
    char name[20];

    printf("Employee name: ");
    scanf("%s",&name);

    printf("Basic salary: ");
    scanf("%f",&basic_sal);

    if (basic_sal<5000)
        x=basic_sal*0.05;
        else if (basic_sal>=5000 && basic_sal<10000)
        x=basic_sal*0.1;
    else (basic_sal>=10000);
        x=basic_sal*0.15;

    new_sal=basic_sal+x;

    printf("\n%s's New Salary is LKR%.2f",name,new_sal);
    return 0;
}
