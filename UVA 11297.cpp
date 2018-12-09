#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int ara[501][501];
int seg_min[501][1500];
int seg_max[501][1500];

void build(int n,int b,int e,int p)
{
    if(b==e)
    {
        seg_min[p][n] = seg_max[p][n] = ara[p][b];
        return;
    }

    int mid = (b+e)/2, left = 2*n, right = left + 1;

    build(left,b,mid,p);
    build(right,mid+1,e,p);

    seg_min[p][n] = min(seg_min[p][left],seg_min[p][right]);
    seg_max[p][n] = max(seg_max[p][left],seg_max[p][right]);
}

int query_seg(int n, int b, int e, int i, int j,int p)
{

    if(i>e||j<b)
        return INT_MAX;

    if(b>=i && e<=j)
        return(i==j) ? ara[p][i] : seg_min[p][n];

    int l = 2*n,r = l + 1;
    int mid = (b+e)/2;

    int p1 = query_seg(l, b, mid,i,j,p);
    int p2 = query_seg(r, mid+1, e,i,j,p);

    return min(p1,p2);

}
pii query(int n,int b,int e,int i,int j,int p)
{
    if(i>e||j<b)
        return {INT_MAX,INT_MIN};

    if(b>=i && e<=j)
        return {seg_min[p][n],seg_max[p][n]};

    int mid = (b+e)/2, left = 2*n, right = left + 1;

    pii p1 = query(left,b,mid,i,j,p);
    pii p2 = query(right,mid+1,e,i,j,p);

    int m = min(p1.first,p2.first);
    int M = max(p1.second,p2.second);

    return {m,M};
}

void update(int n, int b, int e, int i, int val,int p)
{
    if (i > e || i < b) return;
    if (b >= i && e <= i)
    {
        seg_min[p][n] = seg_max[p][n] = val;
        return;
    }

    int left = n* 2,right = left + 1;
    int mid = (b + e) / 2;

    update(left,b,mid,i,val,p);
    update(right,mid+1,e,i,val,p);

    seg_min[p][n] = min(seg_min[p][left],seg_min[p][right]);
    seg_max[p][n] = max(seg_max[p][left],seg_max[p][right]);

}

int main()
{
    int n,q,x1,y1,x2,y2,val;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            scanf("%d",&ara[i][j]);
        build(1,1,n,i);
    }

    scanf("%d",&q);
    char choice[5];

    while(q--)
    {
        scanf("%s",choice);
        if(choice[0]=='q')
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            int m = INT_MAX, M = INT_MIN;
            for(int p=x1;p<=x2;p++)
            {
                pii ans = query(1,1,n,y1,y2,p);
                m = min(m,ans.first);
                M = max(M,ans.second);
            }
            printf("%d %d\n",M,m);
        }
        else
        {
            scanf("%d%d%d",&x1,&y1,&val);
            update(1,1,n,y1,val,x1);
        }
    }

    return 0;
}
