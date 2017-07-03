#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i,D,t,*days,j,index,a;
    scanf("%d\n",&t);
    string *subject,choice;

    for(int i=1;i<=t;i++)
    {
        scanf("%d\n", &j);

        subject = new string [j];
        days = new int [j];

        for(a=0;a<j;a++)
            cin>>subject[a]>>days[a];

        scanf("%d\n",&D);

        index=-1;

        cin>>choice;

        for(a=0;a<j;a++)
            if(choice==subject[a])
            {
                index=a;
                break;
            }

        if(index==-1)
        {
            printf("Case %d: Do your own homework!\n", i);
            delete [] subject;
            delete [] days;
            continue;
        }

        else
        {
            if(days[index]<=D)
            {
                printf("Case %d: Yesss\n", i);
                delete [] subject;
                delete [] days;
                continue;
            }

            else if(days[index]<=D+5)
            {
                printf("Case %d: Late\n", i);
                delete [] subject;
                delete [] days;
                continue;
            }

            else
            {
                printf("Case %d: Do your own homework!\n", i);
                delete [] subject;
                delete [] days;
                continue;
            }
        }
    }
    return 0;
}
