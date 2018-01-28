#include<bits/stdc++.h>
#define MAX 500000
#define INF INT_MAX
using namespace std;

int g[1001][1001],p[1001][1001],cost[1001];

void init(int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            p[i][j] = i;
            g[i][j] = (i==j) ? 0 : INF;
        }
}
void floyedWarshall(int n)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(g[i][k] != INF && g[k][j]!=INF)
                {
                    int v = cost[k];
                    if(k==i||k==j)  v = 0;
                    if(v+g[i][k]+g[k][j]<g[i][j])
                    {
                        g[i][j] = g[i][k]+g[k][j]+v;
                        p[i][j] = p[k][j];;
                    }
                }
            }
}

void pathFind(int s, int d)
{
    if(s==d)
    {
        printf("%d",s);
        return;
    }
    pathFind(s,p[s][d]);
    printf("-->%d",d);
}

int main ()
{

    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t,f;
    char s[MAX];
    vector<int>value;

    scanf("%d\n\n",&t);

    while(t--)
    {
        gets(s);
        value.clear();
        char *pch;
        pch = strtok(s," ");

        while(pch!=NULL)
        {
            value.push_back(atoi(pch));
            pch = strtok(NULL," ");
        }

        init(value.size());

        for(int i=0;i<value.size();i++)
        {
            if(value[i]==-1)    value[i] = INF;
            g[1][i+1] = value[i];
        }

        for(int i=2;i<=value.size();i++)
        {
            for(int j=1;j<=value.size();j++)
            {
                scanf("%d",&f);
                if(f==-1)   f = INF;
                g[i][j] = f;
            }
        }

        for(int i=1;i<=value.size();i++)
            scanf("%d",&cost[i]);

        floyedWarshall(value.size());

        getc(stdin);

        int kase = 0;
        while(gets(s))
        {
            if(!s[0])   break;
            kase++;
            if(kase>1)  printf("\n");
            char *tok;
            int src,dis;
            tok = strtok(s," ");
            src = atoi(tok);
            tok = strtok(NULL," ");
            dis = atoi(tok);
            printf("From %d to %d :\n",src,dis);
            printf("Path: ");
            pathFind(src,dis);
            printf("\nTotal cost : %d\n",g[src][dis]);
        }

        if(t)   printf("\n");
    }
    return 0;
}

