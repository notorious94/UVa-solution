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

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int t,n;
    char s[MAX];
    string p;
    map<string,int>number;
    map<char,char>digit;
    map<string,int>::iterator it;

    digit['A']=digit['B']=digit['C']='2';
    digit['D']=digit['E']=digit['F']='3';
    digit['G']=digit['H']=digit['I']='4';
    digit['J']=digit['K']=digit['L']='5';
    digit['M']=digit['N']=digit['O']='6';
    digit['P']=digit['R']=digit['S']='7';
    digit['T']=digit['U']=digit['V']='8';
    digit['W']=digit['X']=digit['Y']='9';

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",s);
            p.clear();
            for(int i=0;s[i];i++)
            {
                if(isalpha(s[i]))   s[i] = digit[s[i]];
                if(s[i]!='-')       p+=s[i];
                if(p.size()==3)     p+='-';
            }
            number[p]++;
        }
        bool print = false;
        for(it = number.begin();it!=number.end();it++)
            if(it->second>1)
            {
                print = true;
                cout<<it->first<<" "<<it->second<<endl;
            }
        if(!print)  cout<<"No duplicates."<<endl;
        number.clear();
        if(t)   cout<<endl;
    }

    return 0;
}
