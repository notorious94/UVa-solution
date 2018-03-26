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
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

class info
{
public:
    string t,f,l,sA,dep,hP,wP,cM;

    info(char x[],char a[],char c[],char d[],char e[],char f[],char g[])
    {
        dep = x;
        t = a;
        l = c;
        sA = d;
        hP = e;
        wP = f;
        cM = g;
    }

    void _assign(char name[])
    {
        f = name;
    }

    void print()
    {
        printf("----------------------------------------\n");
        printf("%s %s %s\n",t.c_str(),f.c_str(),l.c_str());
        printf("%s\n",sA.c_str());
        printf("Department: %s\n",dep.c_str());
        printf("Home Phone: %s\n",hP.c_str());
        printf("Work Phone: %s\n",wP.c_str());
        printf("Campus Box: %s\n",cM.c_str());

    }

    bool operator < (const info &p) const
    {
        return l < p.l;
    }

};

char s[MAX];
char x[1000],a[10000],b[1000],c[1000],d[1000],e[1000],f[1000],g[1000];

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int test;
    scanf("%d\n",&test);
    vector<info>I;
    while(test)
    {
        gets(s);
        strcpy(x,s);
        while(gets(s))
        {
            if(!s[0])   break;
            char *tok = strtok(s,",");
            strcpy(a,tok);

            tok = strtok(NULL,",");
            strcpy(b,tok);

            tok = strtok(NULL,",");
            strcpy(c,tok);

            tok = strtok(NULL,",");
            strcpy(d,tok);

            tok = strtok(NULL,",");a
            strcpy(e,tok);

            tok = strtok(NULL,",");
            strcpy(f,tok);

            tok = strtok(NULL,",");
            strcpy(g,tok);
            I.push_back(info(x,a,c,d,e,f,g));
            I.back()._assign(b);
        }
        test--;
    }
    sort(all(I));
    for(int i=0;i<I.size();i++)
        I[i].print();

    return 0;
}
