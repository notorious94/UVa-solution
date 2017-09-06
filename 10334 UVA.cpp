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

string sum(string a, string b)
{
    int x,y;
    string ans;
    for(int i=a.size()-1,j=b.size()-1,c=0;i>=0||j>=0||c;i--,j--)
    {
        (i<0) ? x=48 : x = a[i];
        (j<0) ? y=48 : y = b[j];

        c+=(x+y-96);
        if(c>9)
            ans.push_back(c%10+48);
        else
            ans.push_back(c+48);
        c/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string fibo[1001];
    fibo[0]="1";
    fibo[1]="2";

    for(int i=2;i<1001;i++)
        fibo[i]=sum(fibo[i-1],fibo[i-2]);

    int n;

    while(sif(n)!=EOF)
        pf("%s\n",fibo[n].c_str());

    return 0;
}
