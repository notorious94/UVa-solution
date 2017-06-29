#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int r=sqrt(2002),t;
    string s;
    vector<bool>prime(2002, true);
    map<char, int>prime_char;
    map<char, int>::iterator it;
    bool print;

    prime[0]=false;
    prime[1]=false;

    for(int i=2;i<=r;i++)
        if(prime[i])
            for(int j=2;i*j<2002;j++)
                prime[i*j]=false;

    scanf("%d\n", &t);

    for(int i=1;i<=t;i++)
    {
        cin>>s;
        sort(s.begin(), s.end());
        for(int j=0;s[j]!='\0';j++)
            prime_char[s[j]]++;

        print=false;

        printf("Case %d: ", i);

        for(it = prime_char.begin();it!=prime_char.end();it++)
            if(prime[it->second])
            {
                print=true;
                printf("%c",it->first);
            }
        if(print==false)
            printf("empty");
        printf("\n");
        prime_char.clear();
    }
    return 0;
}
