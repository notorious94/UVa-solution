#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pi acos(-1.0)
#define INF INT_MAX

using namespace std;
typedef long long ll;

double graph[101][101];

void init(int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j] = (i==j) ? 0 : INF;
            //path[i][j] = i;
        }
    }
}

double FloydWarshall(int n)
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(graph[i][k]!=INF && graph[k][j]!=INF){
                    if(graph[i][j]>graph[i][k]+graph[k][j]){
                        graph[i][j] = graph[i][k]+graph[k][j];
                        //path[i][j]  = path[k][j];
                    }
                }
    double maxDist = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {            if(graph[i][j]==INF)
                return -1;
            maxDist = max(maxDist,graph[i][j]);
        }
    }
    return maxDist;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test,n;
    double x,y;
    cin>>test;
    for(int kase= 1;kase<=test;kase++)
    {
        vector<pdd>nodes;
        cin>>n;
        init(n);
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            nodes.push_back({x,y});
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double x1 = nodes[i].first;
                double x2 = nodes[j].first;
                double y1 = nodes[i].second;
                double y2 = nodes[j].second;

                double dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
                if(dist<=100)
                {
                    graph[i][j] = sqrt(dist);
                    graph[j][i] = graph[i][j];
                }
            }
        }
        printf("Case #%d:\n",kase);
        double ans = FloydWarshall(n);
        if(ans==-1)
            printf("Send Kurdy\n\n");
        else
            printf("%0.4lf\n\n",ans);
    }

    return 0;
}
