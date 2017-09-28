#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t;
    string s;

    map<string, int>occour;
    set<string>sort_list;
    set<string>::iterator it;

    sif(t);
    getc(stdin);

    while(t--)
    {
        get_stl(s);

        string country;
        bool first_letter = false;

        for(int i=0;s[i]!=0;i++)
        {
            if(isalpha(s[i]))
            {
                country+=s[i];
                if(country.size()==1)
                {
                    first_letter = true;
                }
            }
            if(first_letter==true&&s[i]==32)
                break;
        }

        occour[country]++;
        sort_list.insert(country);

    }

    for(it = sort_list.begin();it!=sort_list.end();it++)
        cout<<*it<<" "<<occour[*it]<<endl;

    return 0;
}
