#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};

int m,n;

bool mirror(char a,char b)
{
    if(tolower(a)==tolower(b))
        return true;

    else if(toupper(a)==toupper(b))
        return true;

    else
        return false;
}

bool match(int c, int i, int j, string g[], string w)
{
    int count = 0;
    int index = 0;

    for(int a=i,b=j; a>=0&&a<m && b>=0&&b<n && w[index]!=0 ;a+=dx[c],b+=dy[c],index++)
    {
        if(mirror(w[index],g[a][b]))
            count++;
        else if(!mirror(w[index],g[a][b]))
            return false;
        if(count==w.size())
            return true;
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t;
    string word;
    sif(t);

    for(int case_no = 1 ; case_no <= t ; case_no++)
    {

        cin>>m>>n;
        string g[m];

        for(int i=0;i<m;i++)
            cin>>g[i];

        int w;

        cin>>w;

        while(w--)
        {
            cin>>word;

            int x,y;

            bool found = false;

            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(mirror(word[0], g[i][j]))
                    {
                        x = i;
                        y = j;

                        for(int c=0;c<8;c++)
                        {
                            if(match(c,x,y,g,word))
                            {
                                found = true;
                                break;
                            }
                        }
                        if(found)
                            break;
                    }
                }
                if(found)
                    break;
            }
            cout<<x+1<<" "<<y+1<<endl;
        }
        if(case_no!=t)
            cout<<endl;
    }
}
