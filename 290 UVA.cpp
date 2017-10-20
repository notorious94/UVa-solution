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

string pos = "0123456789ABCDEF";

int Base(string s)
{
    int b,base=0;
    for(int i=0;s[i];i++)
    {
        if(isalpha(s[i]))   b = s[i]-'A'+11;
        else   b = s[i]-'0'+1;
        if(b>base)  base = b;
    }
    return base;
}

string sum(string a,string b,int base)
{
    string s;
    int x=0,y=0;

    for(int c=0,i=a.size()-1,j=b.size()-1;i>=0||c||j>=0;i--,j--)
    {
        if(i<0)
            x=0;
        else if(x>=0)
        {
            if(isalpha(a[i]))   x = a[i]-'A'+10;
            else   x = a[i]-'0';
        }

        if(j<0)
            y=0;

        else if(y>=0)
        {
            if(isalpha(b[j]))   y = b[j]-'A'+10;
            else   y = b[j]-'0';
        }

        c += (x+y);
        s.push_back(pos[c%base]);
        c/=base;
    }
    reverse(s.begin(),s.end());
    return s;
}

bool palindrome(string s)
{
    int limit = s.size()/2;
    for(int i=0,j=s.size()-1;i<limit;i++,j--)
        if(s[i]!=s[j])  return false;
    return true;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    string s;
    while(cin>>s)
    {
        if(s=="0")
        {
            printf("0 0 0 0 0 0 0 0 0 0 0 0 0 0\n");
            continue;
        }

        int base_s = Base(s);
        for(int i=15;i>=base_s;i--)
        {
            int count = 0;
            string a,b;
            a = s;
            while(1)
            {
                if(palindrome(a))   break;
                count++;
                b=a;
                reverse(b.begin(),b.end());
                a = sum(a,b,i);
            }

            if(i==15)   cout<<count;
            else    cout<<" "<<count;
        }

        for(int i=base_s-1;i>=2;i--)
            printf(" ?");
        cout<<endl;
    }
    return 0;
}
