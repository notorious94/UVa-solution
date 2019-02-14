#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int hist[105];
int grid[105][105];

int getMaxArea(int n)
{
	stack<int> s;
	int max_area = 0,tp,area_with_top;
    int i = 0;
	while (i < n)
	{
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);
		else
		{
			tp = s.top();
			s.pop();
			area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
			max_area = max(max_area,area_with_top);
		}
	}
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
		max_area = max(max_area,area_with_top);
	}
	return max_area;
}
/*
int findArea(int r,int c)
{
    int maxArea = 0;
    memset(hist,0,sizeof(hist));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            (grid[i][j]==0) ? hist[j]=0 : hist[j]++;
        maxArea = max(maxArea,getMaxArea(c));
    }
    cout<<maxArea<<endl;
}
*/
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int r,c;
    while(cin>>r>>c)
    {
        if(r+c==0)  break;
        int maxArea = 0;
        memset(hist,0,sizeof(hist));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                scanf("%d",&grid[i][j]);
                grid[i][j] = !grid[i][j];
                (grid[i][j]==0) ? hist[j]=0 : hist[j]++;
            }
            maxArea = max(maxArea,getMaxArea(c));
        }
        printf("%d\n",maxArea);
    }
    return 0;
}
