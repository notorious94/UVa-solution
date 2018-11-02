#include<bits/stdc++.h>
using namespace std;

char grid[1000][1000];
int ans[1000][1000];
int width[1000];
char s[100000];

int r,c;

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};

bool inBound(int x,int y)
{
    return (x>=0&&x<r&&y>=0&&y<c);
}

void DFS(int n,int x,int y,char c)
{
    grid[x][y] = '*';
    ans[x][y]  =  n;
    for(int i=0; i<8; i++)
    {
        int vx = x+dx[i],vy = y+dy[i];
        if(inBound(vx,vy)&&grid[vx][vy]==c)
            DFS(n,vx,vy,c);
    }
    return;
}
void print_res()
{
    for(int i=0;i<c;i++)
    {
        width[i]=0;
        for(int j=0; j<r; j++)
            width[i]=width[i]>ans[j][i] ? width[i] : ans[j][i];
        int x=1;
        while(true)
        {
            width[i]=width[i]/10;
            if(!width[i])
                break;
            else
                x++;
        }
        width[i]=x;
    }
    c--;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<setw(width[j])<<ans[i][j]<<" ";
        cout<<setw(width[c])<<ans[i][c]<<endl;
    }
    cout<<"%"<<endl;
}
void call()
{
    int component = 1;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
        {
            if(grid[i][j]!='*')
                DFS(component++,i,j,grid[i][j]);
        }
    print_res();
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(gets(s))
    {
        if(s[0]=='%')
        {
            call();
            r = 0,c = 0;
            continue;
        }
        c = (strlen(s)/2) + 1;
        int j = 0;
        for(int i=0; s[i]; i++)
            if(s[i]!=32)    grid[r][j++] = s[i];
        r++;
    }
    call();
    return 0;
}
