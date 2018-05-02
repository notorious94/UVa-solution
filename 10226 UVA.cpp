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
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

struct node
{
    double word;
    bool end_mark;
    node *next[257];
    node()
    {
        end_mark = false;
        word = 0;
        for(int i=0;i<257;i++)
            next[i] = NULL;
    }
}*root;

void insert_word(char s[])
{
    node *c = root;
    for(int i=0;s[i];i++)
    {
        int id = s[i];
        if(c->next[id]==NULL)
            c->next[id] = new node();
        c = c->next[id];
    }
    c->end_mark = true;
    c->word++;
}

double total;

void traverse(node *r,char s[],int level=0)
{
    if(r->end_mark)
    {
        s[level]='\0';
        printf("%s %.4lf\n",s,100.0*(r->word/total));
        return;
    }
    for(int i=0;i<257;i++)
        if(r->next[i])
        {
            s[level] = i;
            traverse(r->next[i],s,level+1);
        }
}

void del(node *r)
{
    for(int i=0;i<257;i++)
        if(r->next[i])
            del(r->next[i]);
    delete(r);
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    char spice[5000];
    scanf("%d\n\n",&t);
    while(t--)
    {
        total = 0;
        root = new node();
        while(gets(spice))
        {
            if(!spice[0]) break;
            total++;
            insert_word(spice);
        }
        traverse(root,spice);
        del(root);
        if(t)   puts("");
    }
    return 0;
}
