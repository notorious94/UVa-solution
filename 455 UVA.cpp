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

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

vector<int>divisor;

void divide(int Len)
{
    int r = sqrt(Len);

    divisor.push_back(1);
    divisor.push_back(Len);

    for(int i=2;i<=r;i++)
        if(Len%i==0)
        {
            divisor.push_back(i);

            if((Len/i)!=i)
                divisor.push_back(Len/i);
        }

    sort(divisor.begin(),divisor.end());
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
    string s,temp;
    sif(n);

    while(n--)
    {
        cin>>s;

        if(s.size()==1)
            divisor.push_back(1);
        else
            divide(s.size());

        for(int i=0;i<divisor.size();i++)
        {
            int limit = divisor[i];
            temp.clear();
            for(int j=0;j<limit;j++)
                temp+=s[j];
            string cpy = temp;
            int c = (s.size()/limit)-1;
            for(int k=1;k<=c;k++)
                temp+=cpy;
            if(temp==s)
            {
                cout<<limit<<endl;
                break;
            }
        }
        if(n)   cout<<endl;
        divisor.clear();
    }
    return 0;
}
