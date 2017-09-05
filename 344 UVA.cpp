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

int digit_freq[101][5];

string add_digit(string r,int q,char c)
{
    for(int i=0;i<q;i++)
        r+=c;
    return r;
}

void int_to_roman(int n)
{
    int q;
    int temp=n;
    string roman;

    while(n)
    {
        if(n>=1000) /// Done
        {
            q = n/1000;
            roman = add_digit(roman,q,'M');
            n%=1000;
        }
        else if(n>=500) /// Done
        {
            if(n<900)
            {
                q = n/500;
                roman = add_digit(roman,q,'D');
                n%=500;
            }
            else
            {
                roman+='C';
                roman+='M';
                n%=100;
            }
        }

        else if(n>=100) /// Done
        {
            if(n<400)
            {
                q = n/100;
                roman = add_digit(roman,q,'C');
                n%=100;
            }
            else
            {
                roman+='C';
                roman+='D';
                n%=100;
            }
        }
        else if(n>=50) /// Done
        {
            if(n<90)
            {
                q = n/50;
                roman = add_digit(roman,q,'L');
                n%=50;
            }
            else
            {
                roman+='X';
                roman+='C';
                n%=10;
            }
        }

        else if(n>=10)
        {
            if(n<40)
            {
                q = n/10;
                roman = add_digit(roman,q,'X');
                n%=10;
            }
            else
            {
                roman+='X';
                roman+='L';
                n%=10;
            }
        }

        else if(n>=5)
        {
            if(n<9)
            {
                q = n/5;
                roman = add_digit(roman,q,'V');
                n%=5;
            }
            else
            {
                roman+='I';
                roman+='X';
                n=0;
            }
        }
        else if(n>=1)
        {
            if(n<4)
            {
                q = n;
                roman = add_digit(roman,q,'I');
                n=0;
            }
            else
            {
                roman+='I';
                roman+='V';
                n=0;
            }
        }
    }
    //cout<<roman<<endl;
    for(int i=0;roman[i]!=0;i++)
    {
        if(roman[i]=='I')
            digit_freq[temp][0]++;
        else if(roman[i]=='V')
            digit_freq[temp][1]++;
        else if(roman[i]=='X')
            digit_freq[temp][2]++;
        else if(roman[i]=='L')
            digit_freq[temp][3]++;
        else if(roman[i]=='C')
            digit_freq[temp][4]++;
    }

    digit_freq[temp][0]+=digit_freq[temp-1][0];
    digit_freq[temp][1]+=digit_freq[temp-1][1];
    digit_freq[temp][2]+=digit_freq[temp-1][2];
    digit_freq[temp][3]+=digit_freq[temp-1][3];
    digit_freq[temp][4]+=digit_freq[temp-1][4];

}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    for(int i=1;i<=100;i++)
        int_to_roman(i);

    while(sif(n))
    {
        if(!n)
            break;
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,digit_freq[n][0],digit_freq[n][1],digit_freq[n][2],digit_freq[n][3],digit_freq[n][4]);
    }

    return 0;
}
