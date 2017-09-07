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

void convert_to_decimal(string n)
{
    int power = n.size()-1;

    int decimal = 0;

    int digit;

    for(int i=0;n[i]!=0;i++)
    {
        if(isalpha(n[i]))
            digit = n[i]-'A'+10;

        else
            digit = n[i]-48;

        decimal += (digit * ceil(pow(16,power)));

        power--;
    }

    pif(decimal);

}

void convert_to_hexadecimal(string n)
{
    int decimal = atoi(n.c_str());

    string hexa;

    while(decimal)
    {
        int m = decimal%16;
        if(m<10)
            hexa.push_back(m+48);
        else if(m==10)
            hexa.push_back('A');
        else if(m==11)
            hexa.push_back('B');
        else if(m==12)
            hexa.push_back('C');
        else if(m==13)
            hexa.push_back('D');
        else if(m==14)
            hexa.push_back('E');
        else if(m==15)
            hexa.push_back('F');

        decimal/=16;
    }

    reverse (hexa.begin(),hexa.end());
    hexa = "0x" + hexa;

    cout<<hexa<<endl;
}
int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    string number;

    while(cin>>number)
    {
        if(number[0]=='-')
            break;

        if(number=="0")
        {
            cout<<"0x0"<<endl;
            continue;
        }

        if(number[0]=='0'&&number[1]=='x')
        {
            number.erase(number.begin(),number.begin()+2);
            convert_to_decimal(number);
        }

        else
            convert_to_hexadecimal(number);
    }

    return 0;
}
