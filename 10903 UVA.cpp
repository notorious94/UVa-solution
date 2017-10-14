#include<bits/stdc++.h>
using namespace std;

class player
{
public:
    double win,loose;
    player(){win=0; loose=0;}
}profile[101];

int game[116][116];

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p1,p2,n,k,kase=0;
    char c1[500],c2[500];
    double final_result;

    game['r']['p']=-1;
    game['r']['s']=1;
    game['s']['p']= 1;
    game['s']['r']= -1;
    game['p']['s']= -1;
    game['p']['r']= 1;

    while(scanf("%d",&n))
    {
        if(!n)  break;

        scanf("%d",&k);
        kase++;

        if(kase>1)
            printf("\n");

        int match = (k*n*(n-1))/2;

        while(match--)
        {
            scanf("%d %s %d %s",&p1,c1,&p2,c2);

            if(game[c1[0]][c2[0]]==1)
            {
                profile[p1].win++;
                profile[p2].loose++;
            }

            else if(game[c1[0]][c2[0]]==-1)
            {
                profile[p1].loose++;
                profile[p2].win++;
            }
        }

        for(int i=1;i<=n;i++)
        {
            if(profile[i].win+profile[i].loose==0)
                printf("-\n");

            else
            {
                final_result = profile[i].win/(profile[i].win+profile[i].loose);
                printf("%.3lf\n",final_result);
            }

            profile[i].win=0;
            profile[i].loose=0;
        }

    }
    return 0;
}
