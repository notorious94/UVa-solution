#include<bits/stdc++.h>
#define MAXC 1000
using namespace std;

int m,n;
int A[101];
int B[101];

int dp[105][105];
bool visit[105][105];

int calcLCS(int i,int j)
{
	if(i >=m || j>=n)
        return 0;

	if(visit[i][j]==true)return dp[i][j];

	int ans=0;
	if(A[i]==B[j]) ans=1+calcLCS(i+1,j+1);
	else
	{
		int val1=calcLCS(i+1,j);
		int val2=calcLCS(i,j+1);
		ans=max(val1,val2);
	}
	visit[i][j]=true;
	return dp[i][j]=ans;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    int kase = 0;
    while(scanf("%d%d",&m,&n))
    {
        if(!m&&!n)  break;

        for(int i=0;i<m;i++)
            scanf("%d",&A[i]);

        for(int i=0;i<n;i++)
            scanf("%d",&B[i]);

        kase++;
        memset(visit, false, sizeof(visit));
        memset(dp, 0 , sizeof(dp));

        printf("Twin Towers #%d\n",kase);
        printf("Number of Tiles : %d\n\n",calcLCS(0,0));

    }
	return 0;
}
