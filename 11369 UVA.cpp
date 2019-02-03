#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,-1,1};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test,n;
    int price[20001];
    cin>>test;
    while(test--)
    {
        scanf("%d",&n);

        for(int i=0;i<n;i++)
            scanf("%d",&price[i]);

        sort(price,price+n);
        reverse(price,price+n);

        int ans = 0;

        for(int i=2;i<n;i+=3)
            ans+=price[i];

        printf("%d\n",ans);
    }
    return 0;
}
