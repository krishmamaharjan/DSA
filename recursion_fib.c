#include <stdio.h>
int fib(int n)
{
   /* int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
    */
    if(n==1 || n==2)
    {
        return 1;
    }
    else

        return fib(n-1) + fib(n-2);

    //return fib(n);
}

int main()
{
    int n;
    printf("Enter the number n : ");
    scanf("%d",&n);
    printf("nth fibonacci number = %d", fib(n));
    getchar();
    return 0;
}
