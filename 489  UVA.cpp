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

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r;
    bool alpha[27];
    int freq[27];
    char solution[MAX],guess[MAX];

    while(scanf("%d",&r))
    {
        if(r<0) break;
        pf("Round %d\n",r);

        for(int i='a';i<='z';i++)
        {
            freq[i-'a'] = 0;
            alpha[i-'a'] = true;
        }

        scanf("%s%s",solution,guess);

        for(int i=0;solution[i];i++)
            freq[solution[i]-'a']++;

        int len = strlen(solution);
        int stroke = 0;

        for(int i=0;guess[i];i++)
        {
            if(alpha[guess[i]-'a'])
            {
                int f = freq[guess[i]-'a'];
                (f) ? len-=f : stroke++;
                alpha[guess[i]-'a'] = false;
            }
            if(!len||stroke>=7)  break;
        }

        if(!len)
            pf("You win.\n");
        else if(stroke>=7)
            pf("You lose.\n");
        else pf("You chickened out.\n");

    }
    return 0;
}
