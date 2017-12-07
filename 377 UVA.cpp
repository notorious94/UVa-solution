#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define INF 0x7FFFFFFF
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define pcc pair<char, char>

typedef long long ll;
typedef unsigned long long ull;

map<pcc, pcc>add;
string cowAdd(string a, string b)
{
    string result;

    char sum, temp, Carry ='0';
    int i,j;

    for(j=b.size()-1,i=a.size()-1;i>=0&&j>=0;i--,j--)
    {
        sum = add[pcc(a[i],b[j])].first;
        temp = add[pcc(a[i],b[j])].second;
        result.push_back(add[pcc(sum, Carry)].first);
        char t = add[pcc(sum, Carry)].second;
        Carry = add[pcc(t,temp)].first;
    }

    while(i>=0)
    {
        if(Carry=='0')
        {
            result.push_back(a[i]);
            i--;
        }
        else
        {
            result.push_back(add[pcc(a[i],Carry)].first);
            Carry = add[pcc(a[i],Carry)].second;
            i--;
        }
    }

    while(j>=0)
    {
        if(Carry=='0')
        {
            result.push_back(b[j]);
            j--;
        }
        else
        {
            result.push_back(add[pcc(b[j],Carry)].first);
            Carry = add[pcc(b[j],Carry)].second;
            j--;
        }
    }
    if(Carry!='0')  result.push_back(Carry);
    reverse(result.begin(), result.end());
    return result;
}

string rightShift(string a)
{
    a = "V" + a;
    a.erase(a.size()-1);
    return a;
}

string leftShift(string a)
{
    a += 'V';
    return a;
}

string padding(string a)
{
    int diff = 8-a.size();

    if(diff<=0)   return a;
    else
    {
        string t;
        for(int i=1;i<=diff;i++)
            t.push_back('V');
        a = t + a;
    }

    return a;
}

void setValue()
{
    add[pcc('0','0')] = pcc('0','0');
    add[pcc('V','V')] = pcc('V','0');
    add[pcc('U','U')] = pcc('C','0');
    add[pcc('C','C')] = pcc('V','U');
    add[pcc('D','D')] = pcc('C','U');
    add[pcc('V','0')] = add[pcc('0','V')] = pcc('V','0');
    add[pcc('C','0')] = add[pcc('0','C')] = pcc('C','0');
    add[pcc('D','0')] = add[pcc('0','D')] = pcc('D','0');
    add[pcc('U','0')] = add[pcc('0','U')] = pcc('U','0');
    add[pcc('V','U')] = add[pcc('U','V')] = pcc('U','0');
    add[pcc('V','C')] = add[pcc('C','V')] = pcc('C','0');
    add[pcc('V','D')] = add[pcc('D','V')] = pcc('D','0');
    add[pcc('U','C')] = add[pcc('C','U')] = pcc('D','0');
    add[pcc('U','D')] = add[pcc('D','U')] = pcc('V','U');
    add[pcc('C','D')] = add[pcc('D','C')] = pcc('U','U');
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    setValue();
    string a,b,r,c;
    int n;

    cin>>n;
    cout<<"COWCULATIONS OUTPUT"<<endl;
    while(n--)
    {
        cin>>a>>b;
        int loop = 3;
        while(loop--)
        {
            cin>>c;
            if(c[0]=='N')   continue;
            else if(c[0]=='R')   b = rightShift(b);
            else if(c[0]=='L')   b = leftShift(b);
            else b = cowAdd(a,b);
        }
        b = padding(b);
        cin>>r;
        (b==r) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;

    return 0;
}
