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

vector<int>data,data_copy;

void insertion_sort();

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int>occur;
    int n;
    while(sif(n)!=EOF)
    {
        if(binary_search(data_copy.begin(), data_copy.end(),n))
            occur[n]++;

        else
        {
            data.push_back(n);
            data_copy.push_back(n);
            insertion_sort();
            occur[n]++;
        }

    }

    for(int i=0;i<data.size();i++)
        pf("%d %d\n", data[i], occur[data[i]]);

    return 0;
}

void insertion_sort()
{
    int size = data_copy.size()-1;

    int value = data_copy[size];
    int hole = size;

    while( hole > 0 && data_copy[hole-1] > value )
    {
        data_copy[hole] = data_copy[hole-1];
        hole--;
    }

    data_copy[hole] = value;
}
