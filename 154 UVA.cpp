#include<bits/stdc++.h>

using namespace std;
int data[101][101];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string s;
    vector<string>board;
    size_t pos;

    while(cin>>s)
    {

        if(s[0]=='e')
        {
            for(int i=0;i<board.size()-1;i++)
            {
                for(int j=i+1;j<board.size();j++)
                {
                    string temp = "";
                    int match = 0;
                    for(int k=0;k<board[j].size();k++)
                    {
                        if(board[j][k]==',')
                        {
                            pos = board[i].find(temp);
                            if(pos!=string::npos)
                                match++;
                            temp.clear();
                            continue;
                        }
                        temp+=board[j][k];
                    }
                    data[i+1][j+1] = data[j+1][i+1] = match;
                }
            }
            int winner = 1, point = INT_MIN;
            for(int i=1;i<=board.size();i++)
            {
                int p=0;
                for(int j=1;j<=board.size();j++)
                    p+=data[i][j];
                if(p>point)
                {
                    point = p;
                    winner = i;
                }
            }
            board.clear();
            memset(data,0,sizeof(data));
            cout<<winner<<endl;
            continue;
        }
        if(s[0]=='#')   break;
        s+=",";
        board.push_back(s);
    }
    return 0;
}
