#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

vector<string>keyword,answer;
int LPS[21][21];

void failure_function(int n)
{
    LPS[n][0] = 0;
    int i=1,len = 0;
    int LenP = keyword[n].size();

    while(i<LenP)
    {
        if(keyword[n][i]==keyword[n][len])    LPS[n][i++] = ++len;
        else{
            if(len)     len = LPS[n][len-1];
            else        LPS[n][i++] = 0;
        }
    }
}

int KMP(char txt[], int n)
{
    int i = 0, j = 0;
    int count = 0;
    int LenS = strlen(txt);
    while(i<LenS)
    {
        if(tolower(txt[i])==keyword[n][j])
        {
            i++;
            j++;
            if(j==keyword[n].size())
            {
                count++;

                int p = i-j-1;
                int l = i;

                if(p>=0&&l<LenS){
                    if(isalpha(txt[p])||isalpha(txt[l]))
                        count--;
                }


                else if(p<0&&l<LenS){
                    if(isalpha(txt[l]))
                        count--;
                }


                else if(p>=0&&l>=LenS){
                    if(isalpha(txt[p]))
                        count--;
                }


                j = LPS[n][j-1];
            }
        }
        else{
            if(j)   j = LPS[n][j-1];
            else    i++;
        }
    }
    return count;
}

int process(char txt[])
{
    int sum = 0;

    for(int i=0;i<keyword.size();i++)
        sum+=KMP(txt,i);

    return sum;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int k,e,kase=0;
    char s[50000];

    while(scanf("%d%d\n",&k,&e)!=EOF)
    {
        keyword.clear();
        answer.clear();
        int excuse = 0;

        for(int i=0;i<k;i++)
        {
            gets(s);
            keyword.push_back(s);
            failure_function(i);
        }

        pf("Excuse Set #%d\n",++kase);

        while(e--)
        {
            gets(s);

            int c = process(s);

            if(c>excuse)
            {
                answer.clear();
                excuse = c;
                answer.push_back(s);
            }

            else if(c==excuse)
                answer.push_back(s);
        }

        for(int i=0;i<answer.size();i++)
            pf("%s\n",answer[i].c_str());

        pf("\n");
    }
    return 0;
}
