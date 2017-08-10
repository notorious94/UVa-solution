#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,max,count,sum;
    vector<int>weight;

    sif(t);

    while(t--)
    {
        sf("%d%d",&n,&max);

        for(int i=0;i<n;i++)
        {
            sif(sum);
            weight.push_back(sum);
        }
        sort(weight.begin(),weight.end());

        sum=0;
        count=0;

        for(int i=0;i<n;i++)
        {
            sum+=weight[i];
            count++;
            if(sum>max)
            {
                --count;
                break;
            }
        }
        pif(count);
        weight.clear();
    }
    return 0;
}
