#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test;
    scanf("%d",&test);
    while(test--)
    {
        int m,n,x;
        scanf("%d%d",&m,&n);
        vector<int>data_content,capacity,data;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            data_content.push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            capacity.push_back(x);
        }
        int content = 0, i = 0,j = 0;
        while(j<n)
        {
            while(j<n&&data.size()==capacity[j])
            {
                printf("%d\n",data[i++]);
                if(++j==n)  break;
            }
            if(j==n)  break;
            data.push_back(data_content[content++]);
            int id = data.size() - 1;
            while(id>0&&data[id-1]>data[id])
            {
                swap(data[id],data[id-1]);
                id--;
            }
        }
        if(test)    puts("");
    }
    return 0;
}
