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

int inversion(string s)
{
    int inverse=0,len = s.size();
    for(int i=0;i<len-1;i++)
    {
        int item = s[i];
        for(int j=i+1;j<len;j++)
            if(item>s[j])
                inverse++;
    }
    return inverse;
}

class data{
public:
    string s;
    int inverse,id;
    data(string a, int in, int ID)
    {
        s = a;
        inverse = in;
        id = ID;
    }
    bool operator < (const data p)
    const   {
        if(inverse!=p.inverse)   return inverse<p.inverse;
        else                            return id<p.id;
    }
};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int test, len, n;
    string str;
    vector<data>arr;

    scanf("%d",&test);

    while(test--)
    {
        arr.clear();

        scanf("%d%d",&len,&n);

        for(int i=1;i<=n;i++)
        {
            cin>>str;
            int val = inversion(str);
            arr.push_back(data(str,val,i));
        }

        sort(arr.begin(),arr.end());

        for(int i=0;i<arr.size();i++)
            cout<<arr[i].s<<endl;

        if(test)    pf("\n");
    }

    return 0;
}
