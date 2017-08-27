#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<char>matrix[101];
    char sentence[101];
    int i, max=0, row=-1;

    while(gets(sentence))
    {
        ++row;/// Tracking number of rows

        for(i=0;sentence[i]!=0;i++)
        /// Inserting Data into 2D Grid
            matrix[row].push_back(sentence[i]);

        if(max<i)/// Length of the string
            max=i;
    }

    for(int j=0;j<max;j++) /// Column Loop
    {
        for(int i=row;i>=0;i--) /// Row Loop
            if(matrix[i].size()>j)
            /// Invalid Index Check
                cout<<matrix[i][j];
            else
                cout<<" ";
        cout<<endl;
    }

    return 0;
}
