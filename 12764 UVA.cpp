#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string emotions[10][3];
    emotions[0][0] = "\\ / ";
    emotions[0][1] = " |  ";
    emotions[0][2] = "/o\\ ";

    emotions[1][0] = " o  ";
    emotions[1][1] = "/|\\ ";
    emotions[1][2] = "/ \\ ";

    emotions[2][0] = "    ";
    emotions[2][1] = "    ";
    emotions[2][2] = "__\\o";

    emotions[3][0] = "    ";
    emotions[3][1] = "    ";
    emotions[3][2] = "\\_\\o";

    emotions[4][0] = "_o_ ";
    emotions[4][1] = " |  ";
    emotions[4][2] = "/ \\ ";

    emotions[5][0] = "\\o/ ";
    emotions[5][1] = " |  ";
    emotions[5][2] = "/ \\ ";

    emotions[6][0] = "\\o_ ";
    emotions[6][1] = "\\|  ";
    emotions[6][2] = " |  ";

    emotions[7][0] = "\\o/ ";
    emotions[7][1] = "\\|/ ";
    emotions[7][2] = "    ";

    emotions[8][0] = "    ";
    emotions[8][1] = " __o";
    emotions[8][2] = "/  |";

    emotions[9][0] = " o  ";
    emotions[9][1] = "( ) ";
    emotions[9][2] = "/ \\ ";

    string s;
    int test;
    cin>>test;
    while(test--)
    {
        cin>>s;
        for(int pass=0;pass<3;pass++)
        {
            cout<<emotions[s[0]-48][pass];
            for(int i=1;s[i];i++)
                cout<<" "<<emotions[s[i]-48][pass];
            puts("");
        }
        puts("");
    }
    return 0;
}
