#include<bits/stdc++.h>
using namespace std;

set<int>pep[101];
int p[101],r[101];

void reset(int n)
{
    for(int i=1;i<=n;i++)
    {
        pep[i].clear();
        p[i] = i;
        r[101] = 1;
    }
}

int Find(int a)
{
    return (a==p[a]) ?  a : p[a] = Find(p[a]);
}

bool make_union(int a,int b)
{
    int u = Find(a);
    int v = Find(b);

    if(u==v)    return false;

    if(r[u]>=r[v])
    {
        r[u]+=r[v];
        p[v] = u;
    }
    else
    {
        r[v]+=r[u];
        p[u] = v;
    }
    return true;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char buf[100];
    int test,P,T,u,v;

    scanf("%d\n\n",&test);

    while(test--)
    {
        gets(buf);

        sscanf(buf,"%d %d",&P,&T);
        reset(P);
        while(gets(buf))
        {
            if(!buf[0]) break;
            sscanf(buf,"%d %d",&u,&v);
            pep[u].insert(v);
        }

        int ans = P;
        for(int i=1;i<=P;i++)
            for(int j=i+1;j<=P;j++)
                if(pep[i]==pep[j]&&make_union(i,j))
                    ans--;

        printf("%d\n",ans);
        if(test)    puts("");
    }
    return 0;
}
