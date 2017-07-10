#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

static string x,y,result;

void sum()
{
    int carry=0,i,sum;

    for(i=x.size()-1;i>=0;i--)
    {
        sum = (x[i]+y[i]-96+carry);
        result.push_back(sum%10+48);
        carry = sum/10;
    }

    if(carry)
        result.push_back(carry +48);

    for(i=result.size()-1;i>=0;i--)
        printf("%c",result.at(i));

    printf("\n");
    result.clear();
}


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b;

    scanf("%d",&n);

    while(n--)
    {
        scanf("%d",&m);

        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            x.push_back(a+48);
            y.push_back(b+48);
        }

        sum();

        if(n!=0)
            printf("\n");

        x.clear();
        y.clear();
    }
    return 0;
}
