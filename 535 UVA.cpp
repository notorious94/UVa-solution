#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi 3.141592653589793
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

double degtoRad(double deg)
{
    return deg * (pi/180.0);
}

double dist(double lat1,double lon1,double lat2,double lon2)
{
    double r = 6378.0;
    double dLat = degtoRad(lat2-lat1);
    double dLon = degtoRad(lon2-lon1);
    double a = sin(dLat/2.0)*sin(dLat/2.0) + cos(degtoRad(lat1))*cos(degtoRad(lat2))*sin(dLon/2.0)*sin(dLon/2.0);
    double c = 2.0*atan2(sqrt(a),sqrt(1.0-a));
    double d = r*c;
    return d;
}


int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    map<string, int>cityID;
    double info[101][2];
    char name[50],name2[50];
    double lat,lon;
    int id = 0;

    while(true)
    {
        scanf("%s",name);

        if(name[0]=='#')   break;

        scanf("%lf%lf",&lat,&lon);

        cityID[name] = ++id;
        info[id][0] = lat;
        info[id][1] = lon;

    }

    while(true)
    {
        scanf("%s%s",name,name2);
        if(name[0]=='#' && name2[0]=='#')   break;

        int x = cityID[name];
        int y = cityID[name2];

        pf("%s - %s\n",name,name2);

        if(!x || !y)
            pf("Unknown\n");
        else{
            double distance = dist(info[x][0],info[x][1],info[y][0],info[y][1]);
            int d = (int)(distance+0.5);
            pf("%u km\n",d);
        }
    }

    return 0;
}
