#include <bits/stdc++.h>
using namespace std;

bool flag[100005];

string solve(string s,int k)
{
    int n = s.size();
    for(int i=0,j=n-1;i<n/2;i++,j--)
    {
        if(s[i]!=s[j])
        {
            flag[i] = true;
            s[i] = s[j] = max(s[i],s[j]);
			k--;
        }
        if(k<0)    return "-1";
    }
    for(int i=0,j=n-1;i<n/2;i++,j--)
	{
        if(s[i]=='9' && s[j]=='9') continue;
        if(k>1 && !flag[i]&& !flag[j])
        {
            s[i]=s[j]='9';
            k-=2;
        }
        else if(k>0&&(!flag[i]||!flag[j]))
        {
            s[i]=s[j]='9';
            k--;
        }
	}
	if(s[n/2]!='9' && k)    s[n/2] = '9';
	return s;
}

int main()
{
    int n,k;
	string s;
	cin>>n>>k>>s;
    cout<<solve(s,k)<<endl;
	return 0;
}
