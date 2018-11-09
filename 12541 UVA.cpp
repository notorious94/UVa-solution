#include<bits/stdc++.h>
using namespace std;
class info
{
public:
    string name;
    int d,m,y;
    info(string s,int day,int month,int year)
    {
        d = day,m = month,y = year;
        name = s;
    }
    bool operator < (info &o)
    {
        if(y!=o.y)
            return y > o.y;
        else if(m!=o.m)
            return m > o.m;
        return d > o.d;
    }
};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,day,month,year;
    char name[500];
    vector<info>data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>name>>day>>month>>year;
        data.push_back(info(name,day,month,year));
    }
    sort(data.begin(),data.end());
    cout<<data[0].name<<endl;
    cout<<data.back().name<<endl;
    return 0;
}
