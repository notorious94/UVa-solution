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

bool chk(int sum,string sign,int number)
{
    if(sign=="<")
        return (sum<number) ? true : false;
    else if(sign=="<=")
        return (sum<=number) ? true : false;
    else if(sign==">")
        return (sum>number) ? true : false;
    else if(sign==">=")
        return (sum>=number) ? true : false;
    else if(sign=="=")
        return (sum==number) ? true : false;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string,int>party;
    int p,g;
    vector<string>tokens;
    string sign,t;
    double v;

    char name[500],line[MAX];

    while(scanf("%d%d",&p,&g)!=EOF)
    {
        party.clear();

        for(int i=1;i<=p;i++)
        {
            scanf("%s%lf",name,&v);
            party[name] = int((v+0.001) * 10);
        }
        getc(stdin);
        for(int kase = 1;kase<=g;kase++)
        {
            gets(line);

            char *pch;

            tokens.clear();

            pch = strtok(line," +");

            while(pch!=NULL)
            {
                tokens.push_back(pch);
                pch = strtok(NULL," +");
            }

            int sum = 0, number=0;

            sign = tokens[tokens.size()-2];
            number = atoi(tokens[tokens.size()-1].c_str())*10;

            for(int i=0;i<tokens.size()-2;i++)
                sum+=party[tokens[i]];

            if(chk(sum,sign,number))
                pf("Guess #%d was correct.\n",kase);
            else
                pf("Guess #%d was incorrect.\n",kase);
        }
    }

    return 0;
}
