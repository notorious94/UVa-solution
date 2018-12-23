#include<bits/stdc++.h>
using namespace std;

set<int>st;
set<int> :: iterator it;
vector<int>score;
string line;

bool visit[61][61][61];
int permutation[181];
int combination[181];

void DP()
{

    for(int i=0;i<70;i++)
        line+='*';

    st.insert(50);

    for(int i=0;i<=20;i++)
        for(int j=1;j<=3;j++)
            st.insert(i*j);

    for(it = st.begin();it!=st.end();it++)
        score.push_back(*it);

    st.clear();

    for(int i=0;i<=180;i++)
    {

        memset(visit,false,sizeof(visit));

        for(int a=0;a<score.size();a++)
        {
            for(int b=0;b<score.size();b++)
            {
                for(int c=0;c<score.size();c++)
                {
                    int total = score[a] + score[b] + score[c];

                    if(total==i)
                    {
                        permutation[i]++;
                        if(visit[score[a]][score[b]][score[c]]==false)
                        {
                            visit[score[a]][score[b]][score[c]] = true;
                            visit[score[a]][score[c]][score[b]] = true;
                            visit[score[b]][score[a]][score[c]] = true;
                            visit[score[b]][score[c]][score[a]] = true;
                            visit[score[c]][score[a]][score[b]] = true;
                            visit[score[c]][score[b]][score[a]] = true;

                            combination[i]++;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n;

    DP();

    while(scanf("%d",&n))
    {
        if(n<=0) break;

        if(n>180||combination[n]==0)
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);
        else
        {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n,combination[n]);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",n,permutation[n]);
        }
        printf("%s\n",line.c_str());

    }
    puts("END OF OUTPUT");
    return 0;
}
