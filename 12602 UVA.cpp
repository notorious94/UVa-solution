#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 99999
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int t;
    string plate,number;

    sif(t);

    while(t--)
    {
        cin>>plate;
        number.clear();

        int part_one = (plate[0]-'A')*676 + (plate[1]-'A')*26 + (plate[2]-'A');

        for(int i=4;plate[i]!=0;i++)
            number+=plate[i];

        int part_two = atoi(number.c_str());

        if(abs(part_two-part_one)<=100)
            cout<<"nice\n";
        else
            cout<<"not nice\n";

    }

    return 0;
}
