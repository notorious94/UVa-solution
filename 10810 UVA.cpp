#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int A[MAX],temp[MAX];

ull merge(int p, int q, int r)
{
    ull inv_count = 0, i = p, j = q, k = p;
    while((i<=q-1)&&(j<=r))
    {
        if(A[i]<=A[j])      temp[k++] = A[i++];
        else
        {
            temp[k++] = A[j++];
            inv_count+=(q-i);
        }
    }
    while(i<=q-1)   temp[k++] = A[i++];
    while(j<=r)     temp[k++] = A[j++];
    for (i=p;i<=r;i++)  A[i] = temp[i];
    return inv_count;
}

ull mergeSort(int p, int r)
{
    ull inv_count = 0;
    if(p<r)
    {
        int q = (p+r)/2;
        inv_count = mergeSort(p,q);
        inv_count += mergeSort(q+1,r);
        inv_count += merge(p,q+1,r);
    }
    return inv_count;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a;
    while(scanf("%d",&n)!=EOF)
    {
        if(!n)  break;
        for(int i=0;i<n;i++)
            scanf("%d",&A[i]);
        pf("%llu\n",mergeSort(0,n-1));
    }
    return 0;
}
