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

typedef long long ll;
typedef unsigned long long ull;

vector<ull>prime_f;
int n;

void pf()
{
    int r = sqrt(n);

    for(int i=2;i<=r;i++)
    {
        if(i>n)
            break;

        if(n%i==0)
            while(n%i==0)
            {
                prime_f.push_back(i);
                n/=i;
            }
    }
    if(n>1)
        prime_f.push_back(n);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        sif(n);
        if(n==0)
            break;
        else if(n==-1)
        {
            pf("-1 = -1 x\n");
            continue;
        }
        else if(n==1)
        {
            pf("1 =\n");
            continue;
        }
        else if(n<0)
        {
            pf("%d = -1 x ",n);
            n*=-1;
        }
        else
            pf("%d = ",n);

        pf();
        for(int i=0;i<prime_f.size()-1;i++)
            pf("%d x ",prime_f[i]);

        pf("%d\n",prime_f[prime_f.size()-1]);
        prime_f.clear();

    }
    return 0;
}
