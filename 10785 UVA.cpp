#include<bits/stdc++.h>
using namespace std;

string v = "AUEOI";
string c = "JSBKTCLDMVNWFXGPYHQZR";

int freq[26];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test,n;
    cin>>test;
    for(int k=1;k<=test;k++)
    {
        cin>>n;

        memset(freq,0,sizeof(freq));

        int p = 0,q = 0;

        vector<char>a,b;

        printf("Case %d: ",k);

        for(int i=1;i<=n;i++)
        {
            if(i&1)
            {
                a.push_back(v[p]);
                if(++freq[v[p]-'A']==21)    p++;
            }
            else
            {
                b.push_back(c[q]);
                if(++freq[c[q]-'A']==5)     q++;
            }
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        p = q = 0;
        for(int i=1;i<=n;i++)
        {
            if(i&1)
                cout<<a[p++];
            else
                cout<<b[q++];
        }

        cout<<endl;
    }
    return 0;
}
