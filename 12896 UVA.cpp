#include<bits/stdc++.h>

using namespace std;

string keypad[10];

void build_keypad()
{
    keypad[1] = ".,?\"";
    keypad[2] = "abc";
    keypad[3] = "def";
    keypad[4] = "ghi";
    keypad[5] = "jkl";
    keypad[6] = "mno";
    keypad[7] = "pqrs";
    keypad[8] = "tuv";
    keypad[9] = "wxyz";
    keypad[0] = " ";
}

int main()
{
    build_keypad();
    int test,n;
    int key[100],freq[100];
    cin>>test;
    while(test--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>key[i];
        for(int i=0;i<n;i++)
            cin>>freq[i];
        for(int i=0;i<n;i++)
            cout<<keypad[key[i]][freq[i]-1];
        cout<<endl;
    }
    return 0;
}
