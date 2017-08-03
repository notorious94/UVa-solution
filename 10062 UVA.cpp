#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string s;
    int c=0;
    while(getline(cin,s))
    {
        c++;
        if(c>1)
            cout<<endl;
        int freq[129]={0};
        int max=-1;
        for(int i=0;s[i]!=0;i++)
        {
            freq[s[i]]++;
            if(max<freq[s[i]])
                max=freq[s[i]];
        }

        for(int i=1;i<=max;i++)
            for(int j=128;j>=0;j--)
                if(freq[j]==i)
                    cout<<j<<" "<<i<<endl;

    }
    return 0;
}
