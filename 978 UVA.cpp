#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test,BG,sGreen,sBlue,power;
    priority_queue<int>q_green,q_blue;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d%d%d",&BG,&sGreen,&sBlue);

        while(sGreen--)
        {
            scanf("%d",&power);
            q_green.push(power);
        }

        while(sBlue--)
        {
            scanf("%d",&power);
            q_blue.push(power);
        }

        while(q_green.size()&&q_blue.size())
        {
            vector<int>tempA,tempB;

            int limit = min(BG,min((int)q_green.size(),(int)q_blue.size()));

            for(int i=0;i<limit;i++)
            {
                int G = q_green.top();
                q_green.pop();
                int B = q_blue.top();
                q_blue.pop();
                if(G>B)                tempA.push_back(G-B);
                else if(B>G)           tempB.push_back(B-G);
            }

            for(int i=0;i<tempA.size();i++)
                q_green.push(tempA[i]);

            for(int i=0;i<tempB.size();i++)
                q_blue.push(tempB[i]);
        }

        if(q_green.size()==0&&q_blue.size()==0)
            puts("green and blue died");

        else if(q_green.size())
        {
            puts("green wins");
            while(q_green.size())
            {
                printf("%d\n",q_green.top());
                q_green.pop();
            }
        }

        else if(q_blue.size())
        {
            puts("blue wins");
            while(q_blue.size())
            {
                printf("%d\n",q_blue.top());
                q_blue.pop();
            }
        }

        if(test)    puts("");

    }

    return 0;

}
