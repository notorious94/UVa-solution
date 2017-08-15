#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[3];
    string name = "ABC";
    while(sf("%d%d%d",&a[0],&a[1],&a[2])!=EOF)
    {
        int count_zero=0,count_one=0;
        int loc_z, loc_o;
        for(int i=0;i<3;i++)
        {
            if(a[i]==0)
            {
                count_zero++;
                loc_z=i;
            }
            else if(a[i])
            {
                count_one++;
                loc_o=i;
            }
        }
        if(count_zero==1)
            pf("%c\n", name[loc_z]);
        else if(count_one==1)
            pf("%c\n", name[loc_o]);
        else
            pf("*\n");
    }

    return 0;
}
