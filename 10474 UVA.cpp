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

    int n,q,marbel_no,location, kase=0;
    vector<int>number;

    while(sf("%d%d", &n,&q))
    {
        if(n==0&&q==0)
            break;

        kase++;
        for(int i=0;i<n;i++)
        {
            sf("%d",&marbel_no);
            number.push_back(marbel_no);
        }

        sort(number.begin(), number.end());

        pf("CASE# %d:\n", kase);

        while(q--)
        {
            sf("%d", &marbel_no);

            location = lower_bound(number.begin(), number.end(), marbel_no) - number.begin();

            if(number[location]==marbel_no)
                pf("%d found at %d\n",marbel_no, location+1);
            else
                pf("%d not found\n", marbel_no);
        }

        number.clear();
    }

    return 0;
}
