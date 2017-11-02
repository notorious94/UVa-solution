#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 2000000
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

    map<char,vector<int> > Map;
    vector<int>distance;

    char s[MAX+2];
    int n;

    while(scanf("%d",&n))
    {
        if(!n)  break;
        Map.clear();
        distance.clear();

        scanf("%s",s);

        for(int i=0;s[i];i++)
            Map[s[i]].push_back(i);

        if(Map['Z'].size())
        {
            printf("0\n");
            continue;
        }

        for(int i=0;i<Map['R'].size();i++)
            for(int j=0;j<Map['D'].size();j++)
                distance.push_back(abs(Map['R'][i]-Map['D'][j]));

        sort(distance.begin(),distance.end());

        if(distance.size()==0)
            printf("0\n");
        else
            printf("%d\n",distance[0]);

    }

    return 0;
}
