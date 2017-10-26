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

int graph[31][31];

void flush(int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            (i==j) ? graph[i][j] = 0 : graph[i][j] = 999999;
}

void floyd_warshal(int n)
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(graph[i][k]+graph[k][j]<graph[i][j])
                    graph[i][j] = graph[i][k]+graph[k][j];
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int dataset,cost,m,n,p,x,y;
    string s,a,b;
    map<string,int>city;

    scanf("%d",&dataset);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    for(int kase = 1;kase<=dataset;kase++)
    {
        printf("DATA SET  %d\n\n",kase);
        cin>>m>>n>>p;
        flush(m);

        for(int i=0;i<m;i++)
        {
            cin>>s;
            city[s]=i;
        }

        while(n--)
        {
            cin>>a>>b;
            x = city[a];
            y = city[b];

            graph[x][y]=1;
            graph[y][x]=1;
        }

        floyd_warshal(m);

        while(p--)
        {
            cin>>cost>>a>>b;
            x = city[a];
            y = city[b];

            if(graph[x][y]==999999)    cout<<"NO SHIPMENT POSSIBLE"<<endl;
            else cout<<"$"<<cost*graph[x][y]*100<<endl;
        }

        cout<<endl;
        city.clear();

    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
