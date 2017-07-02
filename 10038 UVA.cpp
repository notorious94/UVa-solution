#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int i,n,v;
    vector<int>data,dif;
    bool r, e;
    while(cin>>n)
    {
        dif.clear();
        data.clear();
        e=false;
        r=false;
        for(i=0;i<n;i++)
        {
            cin>>v;
            data.push_back(v);
            if(i>0)
            {
                dif.push_back(abs(data[i]-data[i-1]));
                if(abs(data[i]-data[i-1])>n-1)
                    e=true;
            }
        }
        if(n==1)
        {
            printf("Jolly\n");
            continue;
        }
        if(e)
        {
            printf("Not jolly\n");
            continue;
        }
        sort(dif.begin(),dif.end());
        for(i=1;i<dif.size();i++)
            if(dif[i-1]+1!=dif[i])
            {
                r=true;
                printf("Not jolly\n");
                break;
            }
        if(r!=true)
            printf("Jolly\n");
    }
    return 0;
}
