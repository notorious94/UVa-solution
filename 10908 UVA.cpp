#include<bits/stdc++.h>
using namespace std;

int M,N;
char ch;
vector<string>grid;

bool inBound(int x,int y)
{
    return(x>=0&&x<M&&y>=0&&y<N);
}

bool bar_1(int a,int b,int c,int d)
{
    for(int i=a,j=b;j<=d;j++)
        if(grid[i][j]!=ch)
            return false;
    return true;
}

bool bar_2(int a,int b,int c,int d)
{
    for(int i=a,j=b;i<=c;i++)
        if(grid[i][j]!=ch)
            return false;
    return true;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test,q,r,c;
    string s;

    cin>>test;

    while(test--)
    {
        cin>>M>>N>>q;

        grid.clear();

        for(int i=0;i<M;i++)
        {
            cin>>s;
            grid.push_back(s);
        }

        printf("%d %d %d\n",M,N,q);

        while(q--)
        {
            cin>>r>>c;

            ch = grid[r][c];

            int corner_1_and_4 = 1;

            int level = 0;
            int x1,x2,x3,x4;
            int y1,y2,y3,y4;

            for(int i=1;;i++)
            {
                x1 = r - i;
                y1 = c - i;

                x2 = r - i;
                y2 = c + i;

                x3 = r + i;
                y3 = c - i;

                x4 = r + i;
                y4 = c + i;

                if(inBound(x1,y1)&&inBound(x2,y2)&&inBound(x3,y3)&&inBound(x4,y4))
                {
                    if(bar_1(x1,y1,x2,y2)&&bar_2(x1,y1,x3,y3)&&bar_2(x2,y2,x4,y4)&&bar_1(x3,y3,x4,y4))
                        level++;
                    else    break;
                }
                else        break;
            }
            cout<<(2*level)+1<<endl;
        }
    }
    return 0;
}
