#include<bits/stdc++.h>
#define psd pair<string,double>

using namespace std;

int toll[24];

map<string,int>dataset;
map<string,int> :: iterator it;
vector<string>license_no;
vector<psd>result_set;
bool cmp(psd a,psd b)
{
    return a.first<b.first;
}

class record
{
public:
    string direction;
    int month,day,hour,minute,point;

    record(int M,int D,int H,int m,int p,string d)
    {
        month = M, day = D, hour = H,minute = m;
        direction = d;
        point = p;
    }

    bool operator < (const record &other)
    {
        if(month!=other.month)
            return month < other.month;

        if(day!=other.day)
            return day < other.day;

        if(hour!=other.hour)
            return hour < other.hour;

        return minute < other.minute;
    }
};

int get_toll(int h,int m)
{
    for(int i=0;i<24;i++)
    {
        if(h==i&&m<=59)
            return toll[i];
    }
}

vector<record>entry_log[1000];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test;

    scanf("%d\n\n",&test);
    while(test--)
    {
        dataset.clear();
        result_set.clear();
        license_no.clear();

        for(int i=0;i<1000;i++)
            entry_log[i].clear();

        for(int i=0;i<24;i++)
            scanf("%d",&toll[i]);
        char dump[10];

        gets(dump);

        string s;
        int id = 0,record_id;

        while(getline(cin,s)&&cin)
        {
            if(!s[0])   break;

            istringstream iss(s);

            string license,timer,direction,point;
            iss >> license >> timer >> direction >> point;

            int M,D,H,m,p;

            M = (timer[0]-'0')*10 + (timer[1]-'0');
            D = (timer[3]-'0')*10 + (timer[4]-'0');
            H = (timer[6]-'0')*10 + (timer[7]-'0');
            m = (timer[9]-'0')*10 + (timer[10]-'0');
            p = atoi(point.c_str());

            it = dataset.find(license);

            if(it==dataset.end())
            {
                record_id = id;
                license_no.push_back(license);
                dataset[license] = id++;
            }
            else
                record_id = it->second;

            entry_log[record_id].push_back(record(M,D,H,m,p,direction));
        }

        for(int i=0;i<id;i++)
        {
            double expense = 200;
            int trip_count = 0;
            sort(entry_log[i].begin(),entry_log[i].end());
            for(int j=0;j<entry_log[i].size()-1;j++)
            {
                if(entry_log[i][j].direction == "enter" && entry_log[i][j+1].direction=="exit")
                {
                    expense+= 100.0 + abs(entry_log[i][j].point-entry_log[i][j+1].point)*get_toll(entry_log[i][j].hour,entry_log[i][j].minute);
                }
            }
            if(expense!=200)
                result_set.push_back({license_no[i],expense/100.0});
        }
        sort(result_set.begin(),result_set.end(),cmp);
        for(int i=0;i<result_set.size();i++)
            printf("%s $%0.2lf\n",result_set[i].first.c_str(),result_set[i].second);
        if(test)    puts("");
    }

    return 0;
}
