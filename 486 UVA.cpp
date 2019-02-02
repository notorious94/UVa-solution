#include<bits/stdc++.h>

using namespace std;

map<string,int>num;
vector<string>parts,numbers;
char number[50000];
bool sign_flag = false;
void build()
{
    numbers.clear();
    num["zero"] = 0;
    num["one"] = 1;
    num["two"] = 2;
    num["three"] = 3;
    num["four"] = 4;
    num["five"] = 5;
    num["six"] = 6;
    num["seven"] = 7;
    num["eight"] = 8;
    num["nine"] = 9;
    num["ten"] = 10;
    num["eleven"] = 11;
    num["twelve"] = 12;
    num["thirteen"] = 13;
    num["fourteen"] = 14;
    num["fifteen"] = 15;
    num["sixteen"] = 16;
    num["seventeen"] = 17;
    num["eighteen"] = 18;
    num["nineteen"] = 19;
    num["twenty"] = 20;
    num["thirty"] = 30;
    num["forty"] = 40;
    num["fifty"] = 50;
    num["sixty"] = 60;
    num["seventy"] = 70;
    num["eighty"] = 80;
    num["ninety"] = 90;
    num["hundred"] = 100;
    num["thousand"] = 1000;
    num["million"] = 1000000;
    parts.clear();
}

void input()
{
    sign_flag = false;
    string temp;
    for(int i=0;number[i]; i++)
    {
        if(number[i]==32)
        {
            if(temp.size())
            {
                if(temp=="negative")
                    sign_flag = true;
                else
                    numbers.push_back(temp);
                temp.clear();
            }
            continue;
        }
        temp+=number[i];
    }
}

int convert()
{
    reverse(parts.begin(),parts.end());
    int ans = 0;
    for(int i=0;i<parts.size();i++)
    {
        int n = num[parts[i]];
        if(n==100||n==1000||n==1000000)   ans*=n;
        else        ans+=n;
    }
    parts.clear();
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(gets(number))
    {
        build();
        strcat(number," ");
        input();
        int i=numbers.size()-1;
        for(; i>=0; i--)
        {
            if(numbers[i]=="thousand"||numbers[i]=="million")
                break;
            parts.push_back(numbers[i]);
        }
        int a = 0,b = 0,c = 0;
        a = convert();
        for(; i>=0; i--)
        {
            if(numbers[i]=="million")   break;
            parts.push_back(numbers[i]);
        }
        b = convert();
        for(; i>=0; i--)
            parts.push_back(numbers[i]);

        c = convert();
        int final_ans = a+b+c;
        if(sign_flag)
            final_ans*=-1;
        cout<<final_ans<<endl;
    }
    return 0;
}
