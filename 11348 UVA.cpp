#include<bits/stdc++.h>
using namespace std;

int puzzele[10001];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test,n,m,a;
    cin>>test;
    for(int kase=1;kase<=test;kase++)
    {
        cin>>n;

        memset(puzzele,0,sizeof(puzzele));
        set<int>frieds[n+1];
        set<int> :: iterator it;

        for(int f=1;f<=n;f++)
        {
            cin>>m;
            while(m--)
            {
                cin>>a;
                frieds[f].insert(a);
            }
            for(it = frieds[f].begin();it!=frieds[f].end();it++)
                puzzele[*it]++;
        }

        int unique_puzzele = 0;

        for(int i=0;i<=10000;i++)
            if(puzzele[i]==1)
                unique_puzzele++;

        printf("Case %d:",kase);

        for(int i=1;i<=n;i++)
        {
            double total = 0;

            for(it = frieds[i].begin();it!=frieds[i].end();it++)
            {
                int id = *it;
                if(puzzele[id]==1)
                    total++;
            }
            string special = "%";
            double ans = (total / unique_puzzele) * 100.0;
            printf(" %.6lf%c",ans,special[0]);
        }

        cout<<endl;
    }

    return 0;
}
