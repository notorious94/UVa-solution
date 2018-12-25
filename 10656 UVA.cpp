#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,x;
    while(cin>>n)
    {
        if(n==0)
            break;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x)   v.push_back(x);
        }
        if(v.empty())
            puts("0");
        else
        {
            cout<<v[0];
            for(int i=1;i<v.size();i++)
                cout<<" "<<v[i];
            cout<<endl;
        }
    }
    return 0;
}
