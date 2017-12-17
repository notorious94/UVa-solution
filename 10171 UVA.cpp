#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 999999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>

typedef long long ll;
typedef unsigned long long ull;

int manzoor[27][27];
int  miguel[27][27];

int setInfinity()
{
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++){
            manzoor[i][j] = (i==j) ? 0 : INF;
             miguel[i][j] = (i==j) ? 0 : INF;
        }
}

int Floyd_Warshall(int n)
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                manzoor[i][j] = min(manzoor[i][j], manzoor[i][k] + manzoor[k][j]);
                 miguel[i][j] = min( miguel[i][j],  miguel[i][k] +  miguel[k][j]);
            }
}

int ans(int s1,int s2, int m)
{
    int cost,ans = INF;
    vector<int>city;

    for(int i=0;i<m;i++)
    {
        cost = manzoor[s1][i]+miguel[s2][i];
        if(cost<ans)
        {
            ans = cost;
            city.clear();
            city.push_back(i);
        }
        else if(cost==ans)
            city.push_back(i);
    }

    if(s1==s2)    ans = 0;

    if(ans>=INF)
        pf("You will never meet.\n");
    else
    {
        sort(city.begin(),city.end());
        pf("%d",ans);
        if(s1==s2 && s1 >= m)
            pf(" %c\n",s1+'A');
        else
        {
            for(int i=0;i<city.size();i++)
                pf(" %c",'A'+city[i]);
            pf("\n");
        }
    }
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char age[5],way[5],x[5],y[5],s1[5],s2[5];
    int n,c,m;

    while(scanf("%d",&n))
    {
        if(!n)  break;
        m = 0;
        setInfinity(); /// Setting up for Floyed Warshall

        for(int i=0;i<n;i++)
        {
            scanf("%s%s%s%s%d",age,way,x,y,&c);
            m = max(m,x[0]-'A');
            m = max(m,y[0]-'A');
            if(age[0]=='Y') /// under 30
            {
                if(way[0]=='U') /// One Directional
                    manzoor[ x[0]-'A' ][ y[0]-'A' ] = c;

                else /// Bidirectional
                {
                    manzoor[ x[0]-'A' ][ y[0]-'A' ] = c;
                    manzoor[ y[0]-'A' ][ x[0]-'A' ] = c;
                }
            }
            else if(age[0]=='M') /// 30 and Above
            {
                if(way[0]=='U') /// One Directional
                    miguel[ x[0]-'A' ][ y[0]-'A' ] = c;

                else /// Bidirectional
                {
                    miguel[ x[0]-'A' ][ y[0]-'A' ] = c;
                    miguel[ y[0]-'A' ][ x[0]-'A' ] = c;
                }
            }
        }
        scanf("%s%s",s1,s2);
        Floyd_Warshall(++m);
        ans(s1[0]-'A',s2[0]-'A',m);
    }
    return 0;
}
