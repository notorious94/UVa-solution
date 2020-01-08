#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char r_number[1000];

void reverse(char number[])
{
    int i,j,len = strlen(number);
    for(i=0,j=len-1; j>=0; j--,i++)
        r_number[i]=number[j];
    r_number[i]='\0';
}

int isPalindrome(char a[])
{
    int i,j,len = strlen(a);
    for(i=0,j=len-1; i<len/2; i++,j--)
        if(a[i]!=a[j])
            return 0;
    return 1;
}

int main()
{

    int test;
    scanf("%d",&test);

    while(test--)
    {
        char number[1000];
        scanf("%s",number);
        int cycle_len = 0;

        do
        {
            cycle_len++;
            strcpy(r_number,number);
            reverse(number);

            long long a = atoi(number);
            long long b = atoi(r_number),sum = a+b;

            sprintf(number,"%lld",sum);

        }while(isPalindrome(number)==0);

        printf("%d %s\n",cycle_len,number);

    }
    return 0;
}
