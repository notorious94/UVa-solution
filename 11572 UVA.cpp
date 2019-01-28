#include<bits/stdc++.h>
#define pii pair<int,int>
#define pi acos(-1.0)

using namespace std;
typedef long long ll;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

vector<int>ara;
unordered_map<int,int>freq;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test,n,x;

    scanf("%d",&test);

    for(int k=1;k<=test;k++)
    {

        scanf("%d",&n);
        ara.clear();
        freq.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            ara.push_back(x);
        }
        int left = 0,right = 0,len = 0,max_len = 0;
        for(right=0;right<n;right++)
        {
            if(++freq[ara[right]])
            {
                while(freq[ara[right]]>1&&left<=right)
                    freq[ara[left++]]--;
            }
            len = right - left + 1;
            max_len = max(max_len,len);
        }
        printf("%d\n",max_len);

    }
    return 0;
}
