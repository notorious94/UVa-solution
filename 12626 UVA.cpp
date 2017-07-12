#include<bits/stdc++.h>
using namespace std;

#define pf printf
#define sf scanf
#define MAX 600

typedef unsigned long long ll;

int main()
{

    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, count;
    char pizza[MAX + 5];
    map<char, int>element;

    sf("%d\n",&t);

    while(t--)
    {
        element['M']=0;
        element['A']=0;
        element['R']=0;
        element['G']=0;
        element['I']=0;
        element['T']=0;

        sf("%s",pizza);

        for(int i=0;pizza[i]!='\0';i++)
            element[pizza[i]]++;

        count=0;

        while(element.at('M')>=1&&element.at('A')>=3&&element.at('I')>=1&&element.at('R')>=2&&element.at('G')>=1&&element.at('T')>=1)
        {
            count++;
            element.at('M')-=1;
            element.at('A')-=3;
            element.at('R')-=2;
            element.at('T')-=1;
            element.at('G')-=1;
            element.at('I')-=1;
        }
        pf("%d\n", count);
        element.clear();
    }
    return 0;
}
