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

bool isPalindrome(string s)
{
    int l = s.size()/2;
    for(int i=0,j=s.size()-1;j>=0;j--,i++)
        if(s[i]!=s[j])
            return false;
    return true;
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<string>PalindromeStack;
    char str[100];
    while(scanf("%s",str)==1)
    {
        PalindromeStack.clear();
        int n = strlen(str);
        string p;
        for(int i=0;i<n-1;i++)
        {
            p.clear();
            p+=str[i];
            PalindromeStack.insert(p);
            for(int j=i+1;j<n;j++)
            {
                p+=str[j];
                if(isPalindrome(p))
                    PalindromeStack.insert(p);
            }
        }
        p.clear();
        p+=str[n-1];
        PalindromeStack.insert(p);
        pf("The string '%s' contains %d palindromes.\n",str,PalindromeStack.size());
    }
    return 0;
}
