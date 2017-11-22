#include<bits/stdc++.h>

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 1000000
#define INF 0x7FFFFFFF
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define matrix pair<int, int>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

static int dimension[26][2];

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,r,c,p,q1,q2;
    char s[MAX];
    matrix a,b;

    scanf("%d",&n);

    while(n--)
    {
        scanf("%s%d%d",&s,&r,&c);
        dimension[s[0] - 'A'][0] = r;
        dimension[s[0] - 'A'][1] = c;
    }

    while(scanf("%s",&s)!=EOF)
    {
        stack <matrix>data;
        bool error = false;
        int ans = 0;

        for(int i=0;s[i];i++)
        {
            if(isalpha(s[i]))
            {
                r = dimension[s[i]-'A'][0];
                c = dimension[s[i]-'A'][1];
                data.push(matrix(r,c));
            }

            else if(s[i]==')')
            {
                b = data.top();
                data.pop();
                a = data.top();
                data.pop();

                p = a.first;
                q1 = a.second;
                q2 = b.first;
                r = b.second;

                if(q1!=q2)
                {
                    error = true;
                    break;
                }

                ans += p * q1 * r;
                data.push(matrix(p,r));

            }
        }

        if(!error)  printf("%d\n",ans);
        else printf("error\n");

    }

    return 0;
}
