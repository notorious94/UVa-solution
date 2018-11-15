#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test,n,s,q;
    scanf("%d",&test);
    while(test--)
    {
        int watch = 0;
        scanf("%d%d%d",&n,&s,&q);

        stack<int>S;
        queue<int>Q[n];
        int product_cnt[n] = {0};
        int product = 0,sz,id;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&sz);
            product+=sz;
            while(sz--)
            {
                scanf("%d",&id);
                Q[i].push(--id); /// important
            }
        }

        for(int i=0; product; i++,i%=n)
        {
            while(product_cnt[i]&&S.size()) // unloading
            {
                int id = S.top();
                if(id==i)
                {
                    S.pop();
                    watch++;
                    product--;
                    product_cnt[id]--;
                }
                else if(Q[i].size()<q&&S.size())
                {
                    Q[i].push(id);
                    S.pop();
                    watch++;
                }
                else break;
            }
            while(Q[i].size()<q&&S.size()) // unloading
            {
                Q[i].push(S.top());
                watch++;
                S.pop();
            }
            if(S.size()<s) //loading
            {
                while(S.size()<s&&Q[i].size())
                {
                    S.push(Q[i].front());
                    watch++;
                    product_cnt[Q[i].front()]++;
                    Q[i].pop();
                }
            }
            if(product) watch+=2;
        }
        cout<<watch<<endl;
    }
    return 0;
}
