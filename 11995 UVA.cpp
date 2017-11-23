#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 0x7FFFFFFF
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c,e,n,x,y,z;

    while(scanf("%d",&n)!=EOF)
    {
        stack<int>s;
        queue<int>q;
        priority_queue<int>pq;

        bool Q=true,S=true,PQ=true;

        while(n--)
        {
            scanf("%d",&c);

            if(c==1)
            {
                scanf("%d",&e);
                s.push(e);
                q.push(e);

                if(PQ) /// tO AVOID SORTING OPERATION
                    pq.push(e);
            }

            else
            {
                scanf("%d",&e);
                if(s.size())
                {
                    x = s.top();
                    s.pop();
                    if(x!=e)
                        S = false;
                }
                else if(s.size()==0)
                    S = false;

                if(q.size())
                {
                    x = q.front();
                    q.pop();

                    if(x!=e)    Q = false;
                }

                else if(q.size()==0)
                    Q = false;

                if(pq.size())
                {
                    x = pq.top();
                    pq.pop();
                    if(x!=e)    PQ = false;
                }
                else if(pq.size()==0)
                    PQ = false;
            }
        }

        if(!S&&!Q&&!PQ)
            pf("impossible\n");
        else if((S&&Q) || (S&&PQ) || (Q&&PQ))
            pf("not sure\n");
        else if(PQ)
            pf("priority queue\n");
        else if(S)
            pf("stack\n");
        else if(Q)
            pf("queue\n");
    }
    return 0;
}
