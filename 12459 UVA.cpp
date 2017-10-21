#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 0x7FFFFFFF
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};


string sum(string a, string b)
{
    string s;
    int x,y;

    for(int i=a.size()-1,j=b.size()-1,c=0;i>=0||c||j>=0;i--,j--)
    {
        (i<0) ? x = 0 :  x = a[i]-48;
        (j<0) ? y = 0 :  y = b[j]-48;
        c+=(x+y);
        s+=(c%10+48);
        c/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string bee[81];
    bee[1] = "1";
    bee[2] = "2";
    for(int i=3;i<81;i++)
        bee[i]=sum(bee[i-1],bee[i-2]);

    int n;
    while(scanf("%d",&n))
    {
        if(!n)  break;
        printf("%s\n",bee[n].c_str());
    }
    return 0;
}
