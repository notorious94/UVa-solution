#include<bits/stdc++.h>
using namespace std;

/// UVA 324
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

/// Frequency Holder
int digit_frequency[367][10];

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    /// 0! and 1! Factorial both have 1 only
    digit_frequency[0][1]++;
    digit_frequency[1][1]++;

    string factorial;
    factorial.push_back('1');

    for(int carry=0,j=0,i=2;i<367;i++,carry=0) /// Each pass will count the Factorial
    {
        for(j=0;factorial[j]!=0;j++)
        {
            ///Inner loop is keeping the result in string

            carry+=(factorial[j]-48)*i; /// Multiplying

            factorial[j] = (carry>9) ? (carry%10+48) : (carry+48);

            (carry>9) ? carry/=10 : carry=0;

            digit_frequency[i][factorial[j]-48]++; /// Frequency counting
        }

        /// Carry Loop
        while(carry)
        {
            /// Dynamically allocating memory

            (carry>9) ? factorial.push_back(carry%10+48) : factorial.push_back(carry+48);
            (carry>9) ? carry/=10 : carry=0;

            /// Frequency counting of carry
            digit_frequency[i][factorial[j]-48]++;
            j++; ///Increasing Index
        }

        /// Instead of counting the frequency after
        /// Each pass we are doing it in the inner loops
        /// For efficiency
        /*for(int a=0;factorial[a]!=0;a++)
            digit_frequency[i][factorial[a]-48]++;*/
    }

    int n;
    const char c=32;

    while(1)
    {
        sif(n);

        if(n==0)
            break;

        pf("%d! --\n", n);
        for(int i = 0; i < 5; i++)
        {
            if(i)
                pf("    ");
            else
                pf("   ");
            pf("(%d)%5d",i,digit_frequency[n][i]);
        }
        puts("");
        for(int i = 5; i < 10; i++)
        {
            if(i != 5)
                printf("    ");
            else
                printf("   ");
            printf("(%d)%5d", i, digit_frequency[n][i]);
        }
        puts("");
    }
    return 0;
}
