#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int m;
    char val;
    while(scanf("%d",&m)==1)
    {
        vector<pii>ones,threes;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>val;
                if(val=='1')
                    ones.push_back({i,j});
                else if(val=='3')
                    threes.push_back({i,j});
            }
        }

        int ans = INT_MIN;
        for(int i=0;i<ones.size();i++)
        {
            int dist = INT_MAX;
            for(int j=0;j<threes.size();j++)
            {
                int d = abs(ones[i].first-threes[j].first)+abs(ones[i].second-threes[j].second);
                dist = min(dist,d);
            }
            ans = max(ans,dist);
        }
        cout<<ans<<endl;
    }
    return 0;
}


