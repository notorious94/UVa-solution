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

int dimension[26][2];
class matrix
{
public:
    int row,col;
    matrix(){
        row = 1;
        col = 1;
    }
    matrix(int r, int c){
        row = r;
        col = c;
    }
};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,r,c;
    char s[MAX];
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

        int p,q1,q2,r;
        matrix a,b;

        for(int i=0;s[i];i++)
        {
            if(s[i]=='(')   data.push(matrix(1,1));

            else if(isalpha(s[i]))
            {
                int x = dimension[s[i]-'A'][0];
                int y = dimension[s[i]-'A'][1];
                data.push(matrix(x,y));
            }

            else if(s[i]==')')
            {

                b = data.top();
                data.pop();
                a = data.top();
                data.pop();
                data.pop();

                p = a.row;
                q1 = a.col;
                q2 = b.row;
                r = b.col;

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
