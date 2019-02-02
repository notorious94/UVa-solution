#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define all(n) n.rbegin(),n.rend()

vector<int>ans[70];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int member,table;

    while(cin>>member>>table)
    {
        if(!member&&!table)
            break;

        vector<pii>team_info;

        for(int i=0;i<member;i++)
        {
            ans[i].clear();
            int x;
            cin>>x;
            team_info.push_back({x,i});
        }

        sort(all(team_info));

        priority_queue<pii>pq[2];

        for(int i=1;i<=table;i++)
        {
            int cap;
            cin>>cap;
            pq[0].push({cap,i});
        }

        bool turn = false, flag = true;

        for(int i=0;i<member;i++)
        {

            int team_name = team_info[i].second;
            int total_member = team_info[i].first;

            if(total_member>pq[turn].size())
            {
                flag = false;
                break;
            }

            while(pq[turn].size()&&total_member)
            {
                total_member--;
                int table_id = pq[turn].top().second;
                int table_cap = pq[turn].top().first;

                pq[turn].pop();

                ans[team_name].push_back(table_id);

                if(--table_cap)
                    pq[!turn].push({table_cap,table_id});
            }

            while(pq[turn].size())
            {
                pq[!turn].push(pq[turn].top());
                pq[turn].pop();
            }
            turn = !turn;
        }

        if(flag==false)
        {
            puts("0");
            continue;
        }
        puts("1");
        for(int i=0;i<member;i++)
        {
            printf("%d",ans[i][0]);
            for(int j=1;j<ans[i].size();j++)
                printf(" %d",ans[i][j]);
            puts("");
        }
    }
    return 0;
}
