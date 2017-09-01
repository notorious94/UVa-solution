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
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

vector<bool>prime(1000001, true);

void generate_prime()
{
    prime[0] = prime[1] = false;

    int size = prime.size();
    int root = sqrt(size);

    for(int i = 4;i < size; i+=2)
        prime[i]=false;

    for(int i = 3; i <= root; i+=2)
        if(prime[i])
            for(int j=i*i;j<size;j+=2*i)
                prime[j]=false;
}

string trim(string a)
{
    int i;

    for(i=0;a[i]!=0;i++)
        if(a[i]!=48)
            break;

    a.erase(a.begin(), a.begin()+i);

    if(a.size()==0)
        a.push_back('0');

    return a;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    generate_prime();

    string n,temp;
    int i;

    while(cin>>n)
    {
        bool _prime = true;
        bool r_prime = false;

        temp = n;

        i = atoi(n.c_str());

        if(prime[i]==false)
            _prime = false;

        reverse(n.begin(),n.end());
        n = trim(n);

        i = atoi(n.c_str());

        if(prime[i]&& n!=temp)
            r_prime = true;

        if(!_prime)
            pf("%s is not prime.\n",temp.c_str());
        else if(_prime&&!r_prime)
            pf("%s is prime.\n",temp.c_str());
        else if(r_prime)
            pf("%s is emirp.\n", temp.c_str());
    }

    return 0;
}
