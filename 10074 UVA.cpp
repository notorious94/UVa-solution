#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int hist[100];
int grid[100][100];

/*
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
*/
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
            if(s.size()==0 || hist[i]>=hist[s.top()])
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
            }
        }
    }
    return maxArea;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int r,c;
    while(scanf("%d%d",&r,&c))
    {
        if(r==c&&c==0)  break;
        int maxArea = 0;
        memset(hist,0,sizeof(hist));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                scanf("%d",&grid[i][j]);
                grid[i][j] = !grid[i][j];
                (grid[i][j]==0) ? hist[j] = 0 : hist[j]++;
            }
            maxArea = max(maxArea,maxAreaInHistogram(c));
        }
        printf("%d\n",maxArea);
    }
    return 0;
}
