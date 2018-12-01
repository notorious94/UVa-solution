#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

char line[100000];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(gets(line))
    {
        stringstream ss(line);
        int x;
        vector<pii>coefficients;
        for(int p=8;p>=0;p--)
        {
            ss>>x;
            if(x)   coefficients.push_back({x,p});
        }
        if(coefficients.empty())
        {
            puts("0");
            continue;
        }
        else if(coefficients.size()==1&&coefficients[0].second==0)
        {
            printf("%d\n",coefficients[0].first);
            continue;
        }
        for(int i=0;i<coefficients.size();i++)
        {
            if(i==0)
            {
                if(coefficients[i].first!=1&&coefficients[i].first!=-1)
                    printf("%d",coefficients[i].first);
                else if(coefficients[i].first==-1)
                    printf("-");
                if(coefficients[i].second==1)
                    printf("x");
                else if(coefficients[i].second>1)
                    printf("x^%d",coefficients[i].second);
            }
            else
            {
                if(coefficients[i].first<0)
                {
                    if(coefficients[i].second==0||coefficients[i].first<-1)
                        printf(" - %d",-coefficients[i].first);
                    else
                        printf(" - ");
                }
                if(coefficients[i].first>0)
                {
                    if(coefficients[i].second==0||coefficients[i].first>1)
                        printf(" + %d",coefficients[i].first);
                    else
                        printf(" + ");
                }

                if(coefficients[i].second==1)
                    printf("x");
                else if(coefficients[i].second>1)
                    printf("x^%d",coefficients[i].second);

            }

        }
        puts("");
    }
    return 0;
}
