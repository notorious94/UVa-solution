#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string input;
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
        getline(cin,input);
        int r=sqrt(input.size());

        if(r*r!=input.size())
        {
            printf("INVALID\n");
            continue;
        }

        for(int a=0;a<r;a++)
            for(int i=a;i<input.size();i+=r)
                printf("%c",input[i]);

        cout<<endl;
    }
    return 0;
}
