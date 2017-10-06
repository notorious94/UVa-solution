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

int mat[23][23];

void flash(int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j)    mat[i][j]=0;
            else        mat[i][j]=INF;
        }
}

void floyd_warshal(int n)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
}

int add_cost(int n)
{
    int id,cost;
    for(int i=1;i<=n;i++)
    {
        int sum = 0;
        for(int j=1;j<=n;j++)
        {
            sum+=mat[i][j];
        }

        if(i==1)
        {
            cost = sum;
            id = i;
            continue;
        }

        else if(cost>sum)
        {
            cost = sum;
            id = i;
        }
    }
    return id-1;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int n,m,kase=0;
    int i,j,k;
    string name;
    vector<string>team;

    while(scanf("%d%d", &n,&m))
    {
        if(!n&&!m)
            break;

        flash(n);
        team.clear();

        kase++;

        for(int i=1;i<=n;i++)
        {
            cin>>name;
            team.push_back(name);
        }

        while(m--)
        {
            scanf("%d%d%d",&i,&j,&k);
            mat[i][j]=k;
            mat[j][i]=k;
        }

        floyd_warshal(n);
        name = team[add_cost(n)];
        printf("Case #%d : %s\n",kase, name.c_str());

    }
    return 0;
}
