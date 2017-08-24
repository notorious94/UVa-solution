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

int insertion_sort(int array[], int size);

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int test,n,value;
    int *data;
    sif(test);

    while(test--)
    {
        sif(n);

        data = new int [n];

        for(int i=0;i<n;i++)
            sif(data[i]);

        int ans = insertion_sort(data,n);

        pf("Optimal train swapping takes %d swaps.\n",ans);

        delete [] data;

    }

    return 0;
}
int insertion_sort(int array[], int size)
{
    int count=0;

    for(int i = 1; i < size ; i++)
    {
        int value = array[i];
        int hole = i;

        while( hole > 0 && array[hole-1] > value )
        {
            array[hole] = array[hole-1];
            hole--;
            count++;
        }
        array[hole] = value;
    }
    return count;
}
