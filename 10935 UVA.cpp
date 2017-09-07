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
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    vector<int>ans;
    deque<int>card;

    int n;

    while(sif(n))
    {
        if(!n)
            break;
        if(n==1)
        {
            pf("Discarded cards:\n");
            pf("Remaining card: 1\n");
            continue;
        }

        for(int i=1;i<=n;i++)
            card.push_back(i);

        while(card.size()!=1)
        {
            int top = card.front();
            ans.push_back(top);
            card.pop_front();

            top = card.front();
            card.push_back(top);
            card.pop_front();

        }

        pf("Discarded cards: ");
        for(int i=0;i<ans.size()-1;i++)
            cout<<ans[i]<<", ";

        pif(ans[ans.size()-1]);

        pf("Remaining card: %d\n",card.front());

        ans.clear();
        card.clear();
    }

    return 0;
}
