#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string s[105];
    int n,q,p;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>s[i];

        cin>>q;
        while(q--)
        {
            cin>>p;
            p--;
            string rs,ls;
            int right=0,left=0,f1=0,f2=0;
            for(int i=p;i<n;i++)
            {
                if(s[i]!="?")
                {
                    ls = s[i];
                    break;
                }
                left++;
                if(i==n-1)
                {
                    f1 = 1;
                    break;
                }
            }
            for(int i=p;i>=0;i--)
            {
                if(s[i]!="?")
                {
                    rs = s[i];
                    break;
                }
                right++;
                if(i==0)
                {
                    f2 = 1;
                    break;
                }
            }
            if(f1||!left)
            {
                for(int i=0;i<right;i++)
                    cout<<"right of ";
                cout<<rs<<endl;
            }
            else if(f2||!right)
            {
                for(int i=0;i<left;i++)
                    cout<<"left of ";
                cout<<ls<<endl;
            }
            else if(right==left)
                cout<<"middle of "<<rs<<" and "<<ls<<endl;
            else if(left<right)
            {
                for(int i=0;i<left;i++)
                    cout<<"left of ";
                cout<<ls<<endl;
            }
            else
            {
                for(int i=0;i<right;i++)
                    cout<<"right of ";
                cout<<rs<<endl;
            }
        }
    }
    return 0;
}
