#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n,m,k,v;
    vector<vector<int> > data;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        data.assign(1000000,vector<int>());
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&v);
            data[v].push_back(i);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&k,&v);
            if(data[v].size()>=k)
                printf("%d\n",data[v][k-1]);
            else
                printf("0\n");
        }
    }
    return 0;
}
