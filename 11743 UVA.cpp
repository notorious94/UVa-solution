#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t;
    cin>>t;
    string a,b,c,d,s;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        s = a+b+c+d;

        int undoubledsum = 0, doubledsum = 0;

        for(int step = 1, i=s.size()-1;i>=0;i--,step++)
        {
            if(step%2==0)
            {
                int d = (s[i]-48)*2;
                while(d)
                {
                    doubledsum+=(d%10);
                    d/=10;
                }
            }
            else    undoubledsum+=(s[i]-48);
        }

        if((undoubledsum+doubledsum)%10)
            cout<<"Invalid"<<endl;
        else
            cout<<"Valid"<<endl;
    }

    return 0;
}
