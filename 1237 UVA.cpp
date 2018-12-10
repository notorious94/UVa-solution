#include<bits/stdc++.h>

using namespace std;

int database[10000][2];
string company[10000];

int main()
{

    int test,n,q,price;

    cin>>test;

    while(test--)
    {
        cin>>n;

        for(int i=0;i<n;i++)
            cin>>company[i]>>database[i][0]>>database[i][1];

        cin>>q;

        while(q--)
        {
            cin>>price;

            string ans;

            int match = 0;

            for(int i=0;i<n;i++)
            {
                if(price>=database[i][0]&&price<=database[i][1])
                {
                    ans = company[i];
                    match++;
                    if(match>1)
                        break;
                }
            }

            if(match==1)
                cout<<ans<<endl;
            else
                cout<<"UNDETERMINED"<<endl;
        }
        if(test)    puts("");
    }

    return 0;
}
