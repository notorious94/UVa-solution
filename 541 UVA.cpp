#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)

typedef long long ll;
typedef unsigned long long ull;

int mat[100][100];
int d;

bool even()
{
    int rs,cs;

    for(int i=0;i<d;i++) /// Row Sum
    {
        rs=0;
        cs=0;
        for(int j=0;j<d;j++)
        {
            cs+=mat[j][i];
            rs+=mat[i][j];
        }
        if(rs&1||cs&1)
            return false; /// Odd row Found
    }

    return true;  /// Both are even
}
int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        sif(d);
        if(d==0)
            break;
        memset(mat, 0, sizeof(mat));
        for(int i=0;i<d;i++) /// Getting Input
            for(int j=0;j<d;j++)
                sif(mat[i][j]);

        if(even()) /// Initial Check
        {
            printf("OK\n");
            continue;
        }

        bool out=false;

        for(int i=0;i<d;i++) /// Bit changing check
        {
            for(int j=0;j<d;j++)
            {
                int temp=mat[i][j]; /// Keeping temp bit for false condition

                if(mat[i][j])
                    mat[i][j]=0;
                else
                    mat[i][j]=1;

                if(even())
                {
                    pf("Change bit (%d,%d)\n",i+1,j+1); /// True Condition
                    out=true; /// For breaking outer Loop
                    break;
                }

                mat[i][j]=temp; /// Reassigning bit with previous value
            }
            if(out)
                break; /// Outer Loop Break
        }

        if(out==false) /// Condition was never true therefore data is completely corrupted
            pf("Corrupt\n");

    }
    return 0;
}

