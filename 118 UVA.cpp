#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,-1,1};

int row,col;
int grid[51][51];

bool inBound(int x,int y)
{
    return(x>=0&&x<=row&&y>=0&&y<=col);
}

char direction;
int posX,posY;

void changDirection(char way)
{
    if(way=='R')
    {
        if(direction=='N')  direction = 'E';
        else if(direction=='S')  direction = 'W';
        else if(direction=='E')  direction = 'S';
        else if(direction=='W')  direction = 'N';
    }
    else if(way=='L')
    {
        if(direction=='N')  direction = 'W';
        else if(direction=='S')  direction = 'E';
        else if(direction=='E')  direction = 'N';
        else if(direction=='W')  direction = 'S';
    }
}

bool moveForward()
{
    if(direction=='N')
    {
        if(inBound(posX,1+posY)==false)
        {
            if(grid[posX][posY]!=-1)
            {
                printf("%d %d %c LOST\n",posX,posY,direction);
                grid[posX][posY] = -1;
                return false;
            }
            else return true;
        }
        else    posY++;
    }
    else if(direction=='S')
    {
        if(inBound(posX,posY-1)==false)
        {
            if(grid[posX][posY]!=-1)
            {
                printf("%d %d %c LOST\n",posX,posY,direction);
                grid[posX][posY] = -1;
                return false;
            }
            else return true;
        }
        else    posY--;
    }
    else if(direction=='E')
    {
        if(inBound(posX+1,posY)==false)
        {
            if(grid[posX][posY]!=-1)
            {
                printf("%d %d %c LOST\n",posX,posY,direction);
                grid[posX][posY] = -1;
                return false;
            }
            else return true;
        }
        else    posX++;
    }
    else if(direction=='W')
    {
        if(inBound(posX-1,posY)==false)
        {
            if(grid[posX][posY]!=-1)
            {
                printf("%d %d %c LOST\n",posX,posY,direction);
                grid[posX][posY] = -1;
                return false;
            }
            else return true;
        }
        else    posX--;
    }
    return true;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string instruction;
    cin>>row>>col;
    while(cin>>posX>>posY>>direction)
    {
        cin>>instruction;
        int i = 0;
        for(i=0;instruction[i];i++)
        {
            if(instruction[i]=='F'&&moveForward()==false)    break;
            else                    changDirection(instruction[i]);
        }
        if(i==instruction.size())   printf("%d %d %c\n",posX,posY,direction);
    }
    return 0;
}
