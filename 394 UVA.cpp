#include<bits/stdc++.h>
using namespace std;

class info
{
public:
    string name;
    int base,C[11],D,L[11],U[11],I[11];
    info(string n,int b,int c,int d,int l[],int u[])
    {
        name = n;
        base = b;
        D = d;
        C[D] = c;
        for(int i=1;i<=D;i++)
        {
            L[i] = l[i];
            U[i] = u[i];
        }
        int sum = C[D]*L[D];
        for(int i=D-1;i>=1;i--)
        {
            C[i] = C[i+1]*(U[i+1]-L[i+1]+1);
            sum += C[i]*L[i];
        }
        C[0] = base - sum;
    }
    void physical_address()
    {
        printf("%s[",name.c_str());
        int PA = C[0];
        for(int i=1;i<=D;i++)
        {
            scanf("%d",&I[i]);
            PA += C[i]*I[i];
            if(i!=1)    printf(", ");
            printf("%d",I[i]);
        }
        printf("] = %d\n",PA);
    }
};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,r,b,c,d,L[11],U[11];
    char name[1000];
    while(scanf("%d%d",&n,&r)==2)
    {
        map<string,int>id_of_array;
        vector<info>data;
        for(int i=0;i<n;i++)
        {
            scanf("%s",&name);
            scanf("%d%d%d",&b,&c,&d);
            for(int j=1;j<=d;j++)
                scanf("%d%d",&L[j],&U[j]);
            id_of_array[name] = i;
            data.push_back(info(name,b,c,d,L,U));
        }
        while(r--)
        {
            scanf("%s",&name);
            data[id_of_array[name]].physical_address();
        }
        id_of_array.clear();
        data.clear();
    }
    return 0;
}
