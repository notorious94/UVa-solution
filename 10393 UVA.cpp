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
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int f,n;
    string s;
    set<string>ans;
    set<string>::iterator it;

    int alphabet[26];

    alphabet[16] = alphabet[0]  = alphabet[25] = 1;
    alphabet[18] = alphabet[22] = alphabet[23] = 2;
    alphabet[2]  = alphabet[3]  = alphabet[4]  = 3;
    alphabet[1]  = alphabet[5]  = alphabet[6]  = 4;
    alphabet[17] = alphabet[19] = alphabet[21] = 4;
    alphabet[7]  = alphabet[9]  = alphabet[12] = 7;
    alphabet[13] = alphabet[20] = alphabet[24] = 7;
    alphabet[8]  = alphabet[10] = 8;
    alphabet[11] = alphabet[14] = 9;
    alphabet[15] = 10;

    while(scanf("%d%d",&f,&n)!=EOF)
    {
        vector<bool>finger(true,11);

        while(f--)
        {
            int indx;
            scanf("%d",&indx);
            finger[indx]=false;
        }

        int Max = 0;

        while(n--)
        {
            cin>>s;
            bool possible = true;
            for(int i=0;s[i];i++)
            {
                int indx = alphabet[s[i]-'a'];
                if(finger[indx]==false)
                {
                    possible = false;
                    break;
                }
            }
            if(possible)
            {
                if(s.size()>Max)
                {
                    ans.clear();
                    Max = s.size();
                    ans.insert(s);
                }
                else if(s.size()==Max)
                    ans.insert(s);
            }
        }
        cout<<ans.size()<<endl;
        for(it =ans.begin();it!=ans.end();it++)
            cout<<*it<<endl;
        ans.clear();
    }
    return 0;
}
