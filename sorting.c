/*#include<stdio.h>

//void bubblesort(int a[],int n);

int main()
{
    int a[20],i,j,n,temp;
    printf("Enter the total number of elements : ");
    scanf("%d",&n);

    printf("Enter %d elements : \n ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;i++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j]= a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf(" Sorted Array using bubble sort. :\n ");
    for(i=0;i<n;i++)
        printf(" %d\n",a[i]);



    return 0;

}
*/

#include <stdio.h>

int main()
{
  int arr[100], n, i, j, temp;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  for (i = 0 ; i < n - 1; i++)
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j+1]) /* For decreasing order use '<' instead of '>' */
      {
        temp       = arr[j];
        arr[j]   = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  printf("The Sorted elements after using bubble sort :  ");

  for (i = 0; i < n; i++)
     printf("%d  ", arr[i]);

  return 0;
}
