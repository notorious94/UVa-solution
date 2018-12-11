#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

class registers
{
public:
    int q,p;
    registers(int a,int b)
    {
        q = a, p = b;
    }
    bool operator < (const registers &o) const
    {
        if(p!=o.p)
            return p > o.p;
        return q > o.q;
    }
};

int main()
{

    int increament[5000];

    priority_queue<registers>r;
    char s[15];
    int q_num,period,k;

    while(scanf("%s",s))
    {
        if(s[0]=='#')
            break;
        scanf("%d%d",&q_num,&period);
        increament[q_num]=period;
        r.push({q_num,period});
    }

    cin>>k;

    while(k--)
    {
        registers Top = r.top();
        r.pop();
        printf("%d\n",Top.q);
        Top.p+=increament[Top.q];
        r.push(Top);
    }

    return 0;
}
