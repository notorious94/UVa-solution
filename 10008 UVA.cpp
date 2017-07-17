#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 600
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

    map<char,int>alpha;
    vector<int>appear;
    vector<int>::iterator it;

    char str[50000];
    int t;

    while(scanf("%d\n",&t)!=EOF)
    {
        for(int i='A';i<='Z';i++)
            alpha[i]=0;

        while(t--)
        {
            gets(str);
            for(int i=0;str[i]!=0;i++)
                if(isalpha(str[i]))
                    alpha.at(toupper(str[i]))++;
        }

        for(int i='A';i<='Z';i++)
            if(alpha.at(i)>0)
                appear.push_back(alpha.at(i));

        sort(appear.begin(), appear.end());

        for(it=appear.end()-1;it>=appear.begin();it--)
            for(int j='A';j<='Z';j++)
                if(alpha.at(j)== *it)
                {
                    printf("%c %d\n",(char)j,*it);
                    alpha.at(j)=0;
                }

        appear.clear();
    }
    return 0;
}
