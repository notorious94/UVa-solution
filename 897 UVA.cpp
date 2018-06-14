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
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,1,-1,-1,1,-1,1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

int lp[1000];
vector<int>prime,Aprime;

void sieve()
{
    for(int i=2;i<1000;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<1000&&prime[j]<=i;j++)
            lp[i*prime[j]]=prime[j];
    }

    for(int i=0;i<prime.size();i++)
        lp[prime[i]]=-1;
}

void anagramPrime()
{
    for(int i=0;i<prime.size();i++)
    {
        int n = prime[i];
        if(lp[n]==-1)
        {
            string s;
            while(n)
            {
                s+=((n%10)+48);
                n/=10;
            }
            sort(all(s));
            vector<int>temp;
            bool f = true;
            do{
                int r = atoi(s.c_str());

                if(lp[r]!=-1)
                {
                    f = false;
                    break;
                }
                else    temp.push_back(r);

            }while(next_permutation(all(s)));
            if(f)
            {
                for(int j=0;j<temp.size();j++)
                {
                    Aprime.push_back(temp[j]);
                    lp[temp[j]] = 0;
                }
            }
        }
    }
    sort(all(Aprime));
}

int Tens(int n)
{
    if(n>=0&&n<=9) return 0;
    if(n<=99)      return 1;
    return 2;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    anagramPrime();
    int n;
    while(scanf("%d",&n)&&n)
    {
        if(n>991)
            puts("0");
        else{
            vector<int>::iterator it;
            it = upper_bound(all(Aprime),n);
            int m = Aprime[it-Aprime.begin()];
            if(Tens(n)!=Tens(m))    puts("0");
            else                    pif(m);
        }
    }
    return 0;
}
