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

    int n,kase=0;
    char s[50];
    string a,b;
    int wrong[] = { 10, 11, 20, 21, 25, 30, 31, 33, 34, 36, 39, 40, 41, 42, 45, 47, 48, 49, 50, 51, 54, 55, 56, 57, 58, 60, 61, 63, 64, 65, 67, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79};

    while(scanf("%d",&n))
    {
        if(!n)  break;

        kase++;

        if(kase>1)
            cout<<endl;

        if(binary_search(wrong,wrong+42,n))
        {
            printf("There are no solutions for %d.\n",n);
            continue;
        }

        for(int i=1234;i<=98765;i++)
        {
            int j = i*n;
            if(j>=1234 && j<=98765)
            {
                set<char>digit,bdigit;
                bool az = false,bz=false;

                sprintf(s,"%d",j);
                a = s;
                sprintf(s,"%d",i);
                b = s;

                for(int x=0;a[x];x++)
                {
                    if(a[x]==48)    az = true;
                    digit.insert(a[x]);
                }

                if(digit.size()==5)
                {
                    for(int x = 0;b[x];x++)
                    {
                        if(b[x]==48)
                            bz = true;
                        bdigit.insert(b[x]);
                        digit.insert(b[x]);
                    }

                    if(digit.size()==10)
                        printf("%s / %s = %d\n",a.c_str(),b.c_str(),n);
                    if(digit.size()==9 && bdigit.size()==4 && b.size()==4 && az == false && bz== false)
                        printf("%s / 0%s = %d\n",a.c_str(),b.c_str(),n);

                }
            }
        }
    }
    return 0;
}
