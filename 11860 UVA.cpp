#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

char text[200];
vector<int>words_id;
unordered_map<string,int>freq;
unordered_map<int,int>freq2;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test;

    scanf("%d\n",&test);

    for(int kase = 1;kase<=test;kase++)
    {
        words_id.clear();
        freq.clear();
        int total = 0,id = 0;
        while(gets(text))
        {
            if(!strcmp(text,"END"))
                break;
            int n = strlen(text);
            for(int i=0;i<n;i++)
            {
                if(isalpha(text[i]))
                {
                    string w;
                    while(isalpha(text[i])&&i<n)
                        w+=text[i++];
                    if(freq.find(w)==freq.end())
                    {
                        freq[w] = id++;
                        words_id.push_back(id-1);
                        total++;
                    }
                    else
                        words_id.push_back(freq[w]);
                }
            }
        }
        freq2.clear();
        int cnt = 0,p,q,min_diff = INT_MAX;
        for(int l=0,r=0;r<words_id.size();r++)
        {
            if(++freq2[words_id[r]]==1)
                cnt++;
            if(cnt==total)
            {
                while(freq2[words_id[l]]>1&&l<=r)
                    freq2[words_id[l++]]--;
                int diff = r-l+1;
                if(diff<min_diff)
                {
                    min_diff = diff;
                    p = l+1,q = r+1;
                }
            }
        }
        printf("Document %d: %d %d\n",kase,p,q);
    }

    return 0;
}
