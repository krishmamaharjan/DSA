#include<stdio.h>
#include<conio.h>
void toh(int ,char, char, char);
void main()
{
    int n;
    printf("Enter number of disks : ");
    scanf("%d",&n);
    toh(n,'A','C','B');
    getch();
}
void toh(int n,char A, char B, char C)
{
    if(n>0)
    {
        toh(n-1,A,C,B);
        printf("Move disk %d from rod %c to rod %c\n",n,A,B);
        toh(n-1,C,B,A);
    }
}
