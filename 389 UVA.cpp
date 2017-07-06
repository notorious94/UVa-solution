#include<bits/stdc++.h>
using namespace std;

char input[500000];
int length,first;
string number;
static string position="0123456789ABCDEF";

bool check();
void digit();
int convertion_base();
int given_base();
void convert(int from, int to);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w", stdout);

    int to,from,decimal;
    while(gets(input))
    {
        length=strlen(input);
        to=convertion_base();/// Conversion Base
        from=given_base();/// Current Base
        if(check()) /// If all zero
        {
            printf("      0\n");
            continue;
        }
        digit(); /// Extracting Number
        if(number=="1") /// If the actual number is 1
        {
            printf("      1\n");
            number.clear();
            continue;
        }
        convert(from,to); /// Converting into given base
    }
    return 0;
}
void convert(int from, int to) /// The actual magic happens here
{
    int power=number.size()-1;
    int decimal=0,d;

    for(int i=0;number[i]!='\0';i++) /// Converting into Decimal
    {
        if(isdigit(number.at(i)))
            d=number.at(i)-'0';
        else
            d=number.at(i)-'A'+10;

        decimal += (d*ceil(pow(from,power)));
        power--;
    }
    int i=1,m;
    while(pow(to,i)<=decimal)/// Finding out the length of the string
        i++;
    if(i>7)/// Program will pass out if the string length is greater than 7
    {
        printf("  ERROR\n");
        number.clear();
        return;
    }
    char str[i];
    str[i]='\0';

    for(--i;i>=0;i--)
    {
        m=decimal%to;
        str[i]=position.at(m); /// Accessing Positional Number after each MOD
        decimal/=to;
    }
    printf("%7s\n",str);
    number.clear();
    return;
}
void digit() /// Extracting the actual number
{
    for(;input[first]!='\0';first++)
        if(isalpha(input[first])||isdigit(input[first]))
            number.push_back(input[first]);
}
bool check()
{
    for(int i=0;i<length;i++)
        if(input[i]!=32&&input[i]!='0')
        {
            first=i; /// Where the number will actually start from
            return false;
        }
    return true;
}
int given_base()
{
    int i;
    char from[10];

    for(i=length-1;;i--)
        if(isdigit(input[i]))
            break;
    if(isdigit(input[i-1]))
    {
        from[0]=input[i-1];
        from[1]=input[i];
        from[2]='\0';
        input[i-1]='\0';
        length=strlen(input);
        return atoi(from);
    }
    else
    {
        from[0]=input[i];
        from[1]='\0';
        input[i]='\0';
        length=strlen(input);
        return atoi(from);
    }
}
int convertion_base() /// Default base
{
    int i=length-1;
    char to[10];
    if(isdigit(input[i-1]))
    {
        to[0]=input[i-1];
        input[i-1]=32;
        to[1]=input[i];
        input[i]=32;
        to[2]='\0';
        return atoi(to);
    }
    else
    {
        to[0]=input[i];
        input[i]=32;
        to[1]='\0';
        return atoi(to);
    }
}
