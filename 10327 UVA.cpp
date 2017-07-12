#include<bits/stdc++.h>
using namespace std;

///Template Starts Here

#define pf printf
#define sf scanf
#define pb push_back
#define MAX 600

typedef long long ll;
typedef unsigned long long ull;


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,v;

    vector<int>data;

    while(sf("%d", &n)==1)
    {
        for(int i=0;i<n;i++)
        {
            sf("%d",&v);
            data.pb(v);
        }
        int count=0;
        bool flag;
        for(int i=1;i<n;i++)
        {
            flag=true;

            for(int j=0;j<n-1;j++)
            {
                if(data[j]>data[j+1])
                {
                    swap(data[j],data[j+1]);
                    count++;
                    flag=false;
                }
            }
            if(flag)
                break;
        }
        pf("Minimum exchange operations : %d\n", count);
        data.clear();
    }
    return 0;
}
