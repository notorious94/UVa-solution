#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    map<char, double>mole;

    mole['C'] = 12.01;
    mole['H'] = 1.008;
    mole['O'] = 16.00;
    mole['N'] = 14.01;

    int t;
    char m;
    char str[MAX*2];
    sif(t);

    while(t--)
    {
        sf("%s",str);

        double sum = 0,n;
        string number;
        number.clear();

        for(int i=0;str[i]!=0;i++)
        {
            if(isalpha(str[i]))
            {
                m = str[i];

                if(!str[i+1]) ///Null Char Case
                {
                    sum += mole[m];
                    break;
                }
                else if(isdigit(str[i+1])==false) /// No leading digit case
                {
                    sum += mole[m];
                    continue;
                }
                else if(isdigit(str[i+1]))
                {
                    i++;

                    while(1)
                    {
                        if(str[i]==0||isalpha(str[i]))
                        {
                            i--;
                            break;
                        }

                        number += str[i];
                        i++;
                    }

                    n = atoi(number.c_str());

                    sum += 1.0*n*mole[m];

                    number.clear();
                }
            }
        }
        pf("%.3lf\n",sum);
    }
    return 0;
}
