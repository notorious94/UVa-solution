#include<bits/stdc++.h>
using namespace std;

int t[20],r[20],h[20];

bool T[20][20],R[20][20],H[20][20];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int travel,resturant,hotel;
    int permission;

    while(cin>>travel>>resturant>>hotel)
    {
        memset(T,false,sizeof(T));
        memset(R,false,sizeof(R));
        memset(H,false,sizeof(H));

        for(int i=0;i<travel;i++)
        {
            scanf("%d",&t[i]);
            for(int j=0;j<resturant;j++)
            {
                scanf("%d",&permission);
                if(permission==0)
                    T[i][j] = true;
            }
        }

        for(int i=0;i<resturant;i++)
        {
            scanf("%d",&r[i]);
            for(int j=0;j<hotel;j++)
            {
                scanf("%d",&permission);
                if(permission==0)
                    R[i][j] = true;
            }
        }
        for(int i=0;i<hotel;i++)
        {
            scanf("%d",&h[i]);
            for(int j=0;j<travel;j++)
            {
                scanf("%d",&permission);
                if(permission==0)
                    H[i][j] = true;
            }
        }
        int price = INT_MAX;
        int a,b,c;
        for(int i=0;i<travel;i++)
        {
            for(int j=0;j<resturant;j++)
            {
                if(T[i][j])
                {
                    for(int k=0;k<hotel;k++)
                    {
                        if(R[j][k]&&H[k][i])
                        {
                            if(price>t[i]+r[j]+h[k])
                            {
                                price = t[i]+r[j]+h[k];
                                a = i, b = j, c = k;
                            }
                        }
                    }
                }
            }
        }
        if(price!=INT_MAX)
            printf("%d %d %d:%d\n",a,b,c,price);
        else
            puts("Don't get married!");
    }
    return 0;
}
