#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int test;
    string s;
    scanf("%d\n",&test);

    while(test--)
    {
        getline(cin,s);
        ll leftUp = 0,leftDown = 1;
        ll rightUp = 1,rightDown = 0;
        ll midUp, miidDown;
        for(int i=0;s[i];i++)
        {
            midUp = leftUp + rightUp;
            miidDown = leftDown + rightDown;
            if(s[i] == 'R')
            {
                leftUp = midUp;
                leftDown = miidDown;
            }
            if(s[i] == 'L')
            {
                rightUp = midUp;
                rightDown = miidDown;
            }
        }
        cout<<leftUp+rightUp<<"/"<<leftDown+rightDown<<endl;
    }
    return 0;
}
