#include<bits/stdc++.h>
#define psi pair<string,int>

using namespace std;
typedef long long ll;

map<string,set<int> > team_info;
map<string,set<int> > :: const_iterator team;
vector<psi>projects;

bool cmp(psi a,psi b)
{
    if(a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char name[5000];
    while(gets(name))
    {
        if(name[0]=='0')    break;
        else if(name[0]=='1')
        {
            for(team = team_info.begin();team!=team_info.end();team++)
            {
                if(team->second.size()==1)
                    projects[*team->second.begin()].second++;
            }

            sort(projects.begin(),projects.end(),cmp);

            for(int i=0;i<projects.size();i++)
                cout<<projects[i].first<<" "<<projects[i].second<<endl;

            projects.clear();
            team_info.clear();

        }
        else if(name[0]>='a' && name[0]<='z')
            team_info[name].insert(projects.size()-1);
        else
            projects.push_back(psi(name,0));
    }
    return 0;
}
