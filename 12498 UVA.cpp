#include<bits/stdc++.h>
using namespace std;

int row,col;
vector<string>grid;
int ans = INT_MAX;

void chk(int c)
{
    int shift = 0;
    for(int i=0;i<row;i++)
    {
        if(grid[i][c]=='1')
        {
            int dist1 = INT_MAX,dist2 = INT_MAX;
            for(int a=c-1;a>=0;a--) // moving left
            {
                if(grid[i][a]=='0')
                {
                    dist1 = abs(a-c);
                    break;
                }
            }
            for(int a=c+1;a<col;a++) // moving right
            {
                if(grid[i][a]=='0')
                {
                    dist2 = abs(a-c);
                    break;
                }
            }
            int min_dist = min(dist1,dist2);
            if(min_dist==INT_MAX)
                return;
            shift += min_dist;
        }
    }
    ans = min(ans,shift);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test;
    cin>>test;
    char b[1000];
    for(int kase=1;kase<=test;kase++)
    {
        scanf("%d%d",&row,&col);
        grid.clear();
        ans = INT_MAX;

        for(int i=0;i<row;i++)
        {
            scanf("%s",b);
            grid.push_back(b);
        }

        for(int c=0;c<col;c++)
            chk(c);

        if(ans ==INT_MAX)   ans = -1;

        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}
