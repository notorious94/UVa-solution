#include<bits/stdc++.h>
using namespace std;

string sum(string a, string b)
{
    int x,y;
    string ans;

    for(int i=a.size()-1,j=b.size()-1,c=0;i>=0||j>=0||c;i--,j--)
    {
        (i<0) ? x=48 : x = a[i];
        (j<0) ? y=48 : y = b[j];

        c+=(x+y-96);
        if(c>9)
            ans.push_back(c%10+48);
        else
            ans.push_back(c+48);
        c/=10;
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

string multiply(string a, string b)
{
    string M ="0";

    if(a=="0"||b=="0")
        return "0";

    else if(a=="1")
        return b;

    else if(b=="1")
        return a;

    for(int p=0, i=b.size()-1;i>=0;i--,p++)
    {
        string t;
        int c=0;

        for(int j=a.size()-1;j>=0;j--)
        {
            c+=((b[i]-48)*(a[j]-48));
            (c>9) ? t+=(c%10+48) : t+=(c+48);
            c/=10;
        }

        if(c)   t+=(c+48);

        for(int x=1;x<=p;x++)
            t = "0" + t;

        reverse(t.begin(),t.end());

        M = sum (M, t);
    }

    return M;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    string power[16][151];
    string ans[150][16];

    for(int i=0;i<=15;i++)
    {
        char a[52];
        sprintf(a, "%d", i);
        string c = "1",A=a;
        for(int j=1;j<=150;j++)
        {
            c = multiply(c,A);
            sprintf(a,"%d",j);
            string x = a;
            power[i][j] = multiply(c,x);
        }
    }

    for(int a=0;a<=15;a++)
    {
        string s = "0";
        for(int i=1;i<=150;i++)
        {
            s = sum(s,power[a][i]);
            ans[i][a] = s;
        }
    }

    int n,a;

    while(scanf("%d%d",&n,&a)!=EOF)
        printf("%s\n",ans[n][a].c_str());

    return 0;
}
