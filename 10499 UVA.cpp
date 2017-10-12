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

    string a,b="25";

    char temp[500],c='%';

    int n;

    while(scanf("%d",&n)!=EOF)
    {

        if(n <0)
            break;

        if(n==1||!n)
        {
            printf("0%c\n",c);
            continue;
        }
        sprintf(temp,"%d",n);
        a=temp;
        string r = multiply(a,b);
        printf("%s%c\n",r.c_str(),c);
    }

    return 0;
}
