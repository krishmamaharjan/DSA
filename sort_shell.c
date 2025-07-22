#include<stdio.h>
/*void ShellSort(int a[], int n)
{
    int i, j, inc, tmp;
    for(increment = n/2; increment > 0; increment /= 2)
    {
        for(i = increment; i < n; i++)
        {
            tmp = a[i];
            for(j = i; j >= increment; j -= increment)
            {
                if(tmp < a[j-increment])
                    a[j] = a[j-increment];
                else
                    break;
            }
            a[j] = tmp;
        }
    }
}*/

int main()
{
    int i, n, a[10],j, inc, temp;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    //ShellSort(a,n);


    for(inc = n/2; inc > 0; inc /= 2)
    {
        for(i = inc ; i < n; i++)
        {
            temp = a[i];
            for(j = i; j >= inc; j -= inc)
            {
                if(temp < a[j-inc])
                    a[j] = a[j-inc];
                else
                    break;
            }
            a[j] = temp;
        }
    }

    printf("The sorted elements after using shell sort :  ");
    for(i = 0; i < n; i++)
        printf("%d  ",a[i]);
    printf("\n");
    return 0;
}
