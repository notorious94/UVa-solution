#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t,n;
    map<char, int>stat;

    stat['B']=0;
    stat['W']=0;
    stat['T']=0;
    stat['A']=0;

    char cmd[12];

    scanf("%d",&t);

    for(int i=1;i<=t;i++)
    {
        scanf("%d\n", &n);
        scanf("%s", cmd);
        printf("Case %d: ", i);
        for(int j=0;j<n;j++)
            stat[cmd[j]]++;
        if(stat['A']==n)
            printf("ABANDONED");
        else if(stat['B']+stat['A']==n)
            printf("BANGLAWASH");
        else if(stat['W']+stat['A']==n)
            printf("WHITEWASH");
        else if(stat['B']>stat['W'])
            printf("BANGLADESH %d - %d",stat['B'],stat['W']);
        else if(stat['W']>stat['B'])
            printf("WWW %d - %d",stat['W'],stat['B']);
        else
            printf("DRAW %d %d",stat['B'],stat['T']);
        printf("\n");
        stat.clear();
    }
    return 0;
}
