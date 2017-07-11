#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int n,p,m,d,a,b,min;

    vector<int>book;

    bool c;

    while(scanf("%d",&n)!=EOF)
    {
        c=true;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&p);
            book.push_back(p);
        }
        scanf("%d",&m);
        sort(book.begin(),book.end());

        for(int i=0;i<n;i++)
            if(binary_search(book.begin()+i+1,book.end(), m-book.at(i)))
            {
                d=abs(book.at(i)-(m-book.at(i)));
                if(c)
                {
                    min=d;
                    a=book.at(i);
                    b=m-book.at(i);
                    c=false;
                    continue;
                }
                if(min>d)
                {
                    min=d;
                    a=book.at(i);
                    b=m-book.at(i);
                }
            }
        if(a>b)
            swap(a,b);
        printf("Peter should buy books whose prices are %d and %d.\n\n",a,b);
        book.clear();

    }
    return 0;
}
