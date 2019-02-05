#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

vector<string>tray;
unordered_map<string,int>freq;
char fragment[500005];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test,k = 0;
    scanf("%d\n",&test);

    while(test--)
    {
        if(++k>1)   cout<<endl;
        tray.clear();
        freq.clear();
        while(gets(fragment))
        {
            if(fragment[0]==0)    break;
            tray.push_back(fragment);
        }
        int mf = tray.size()/2;
        int flag = true;
        for(int i=0;flag&&i<tray.size()-1;i++)
        {
            for(int j=i+1;flag&&j<tray.size();j++)
            {
                string file1 = tray[i]+tray[j];
                string file2 = tray[j]+tray[i];
                int a = ++freq[file1],b=0;
                if(file1!=file2)
                    b = ++freq[file2];
                if(a==mf)
                {
                    cout<<file1<<endl;
                    flag = false;
                }
                else if(b==mf)
                {
                    cout<<file2<<endl;
                    flag = false;
                }
            }
        }
    }

    return 0;
}
