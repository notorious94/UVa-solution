#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k,v;

    map<int, vector<int> > index;

    while(scanf("%d%d", &n, &m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&k);
            index[k].push_back(i);
        }

        while(m--)
        {
            scanf("%d%d",&k, &v);
            if(k>index[v].size())
                printf("0\n");
            else
                printf("%d\n",index[v][k-1]);
        }

        index.clear();
    }

    return 0;
}
