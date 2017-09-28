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

int convert(string n)
{
    int power = n.size()-1;
    int decimal = 0;

    for(int i=0;n[i]!=0;i++)
    {
        decimal += ceil(pow(16, power)*(n[i]-48));
        power--;
    }

    int b2 = __builtin_popcount(decimal);

    return b2;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    string n;
    int t;
    cin>>t;

    while(t--)
    {
        cin>>n;
        int decimal = atoi(n.c_str());
        int b1 = __builtin_popcount(decimal);
        int b2 = convert(n);
        cout<<b1<<" "<<b2<<endl;
    }

    return 0;
}
