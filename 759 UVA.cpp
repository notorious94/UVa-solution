#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

map<char,int>value;
string int_to_roman(int n)
{
    string C[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string I[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};

    string thousand;

    int q = n/1000;
    for(int i=0;i<q;i++)
        thousand+="M";

    string hundred = C[(n%1000)/100];
    string ten = X[(n%100)/10];
    string one = I[n%10];

    string roman = thousand + hundred + ten + one;

    return roman;

}
int roman_to_integer(char roman[])
{
    int decimal = 0;
    int len = strlen(roman);

    for(int i=0;i<len-1;i++)
    {
        int s1 = value[roman[i]];
        int s2 = value[roman[i+1]];

        if(s1<s2)
            decimal-=s1;
        else
            decimal +=s1;
    }

    decimal += value[roman[len-1]];

    return decimal;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    value['M'] = 1000;
    value['D'] = 500;
    value['C'] = 100;
    value['L'] = 50;
    value['X'] = 10;
    value['V'] = 5;
    value['I'] = 1;

    char roman[50000];
    string valid_roman[4000];

    for(int i=1;i<4000;i++)
        valid_roman[i]=int_to_roman(i);

    while(gets(roman))
    {
        if(roman[0]==0)
        {
            pf("0\n");
            continue;
        }

        int year = roman_to_integer(roman);

        if(year>=4000)
        {
            pf("This is not a valid number\n");
            continue;
        }

        else if(roman == valid_roman[year])
            pif(year);

        else
            pf("This is not a valid number\n");
    }
    return 0;
}
