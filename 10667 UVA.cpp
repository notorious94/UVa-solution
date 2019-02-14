#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,-1,1};

int hist[100];
int grid[100][100];

int maxAreaInHistogram(int len)
{
    stack<int>s;
    s.push(0);
    int i,top,area,maxArea=-1;
    for(i=1; i<=len; i++)
    {
        if(i==len)
        {
            while(s.size())
            {
                top = s.top();
                s.pop();
                if(s.size()==0)
                    area = hist[top]*i;
                else
                {
                    int stackTop = s.top();
                    area = hist[top]*(i-1-stackTop);
                }
                maxArea = max(area,maxArea);
            }
        }
        else
        {
            if(hist[i]>=hist[s.top()])
                s.push(i);
            else
            {
                while(s.size())
                {
                    if(hist[s.top()]<=hist[i])
                    {
                        s.push(i);
                        break;
                    }
                    top = s.top();
                    s.pop();
                    if(s.size()==0)
                        area = hist[top]*i;
                    else
                    {
                        int stackTop = s.top();
                        area = hist[top]*(i-1-stackTop);
                    }
                    maxArea = max(area,maxArea);
                }
                if(s.size()==0) s.push(i);
            }
        }
    }
    return maxArea;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test,s,q,r1,r2,c1,c2;

    cin>>test;
    while(test--)
    {
        cin>>s>>q;

        for(int i=0;i<s;i++)
            for(int j=0;j<s;j++)
                grid[i][j] = 1;

        int total = s*s;

        //q = 1;

        while(q--)
        {
            cin>>r1>>c1;
            cin>>r2>>c2;

            for(int a=r1;total&&a<=r2;a++)
            {
                for(int b=c1;total&&b<=c2;b++)
                {
                    //cout<<a<<" "<<b<<endl;
                    if(grid[a-1][b-1])
                    {
                        grid[a-1][b-1] = 0;
                        total--;
                    }
                }
            }
        }

        int ans = 0;
        memset(hist,0,sizeof(hist));
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<s;j++)
            {
                //cout<<grid[i][j]<<" ";
                (grid[i][j]==0) ? hist[j] = 0 : hist[j]++;
            }
            ans = max(ans,maxAreaInHistogram(s));
        }
        cout<<ans<<endl;
    }

    return 0;
}

