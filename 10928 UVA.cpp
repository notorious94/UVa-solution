#include<bits/stdc++.h>
using namespace std;

char line[1000000];
int cnt[10001];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int P,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d\n",&P);
        int min_neighbour = INT_MAX;
        vector<int>result;
        for(int i=1;i<=P;i++)
        {
            gets(line);
            cnt[i] = 1;
            for(int j=0;line[j];j++)
                if(line[j]==32) cnt[i]++;
            if(cnt[i]<min_neighbour)
            {
                min_neighbour = cnt[i];
                result.clear();
                result.push_back(i);
            }
            else if(min_neighbour==cnt[i])
                result.push_back(i);
        }
        printf("%d",result[0]);
        for(int i=1;i<result.size();i++)
            printf(" %d",result[i]);
        puts("");
        if(t)   gets(line);
    }
    return 0;
}
