#include<bits/stdc++.h>
using namespace std;
int tree[3*1010];
int A[1010];
int prop[3*1010];
int n;
void create_tree(int node,int st,int ed)
{
    if(st == ed)
    {
        tree[node] = A[st];
        prop[node] = 0;
        return ;
    }
    int md = (st + ed)/2;
    int lf = 2 * node;
    int rg = lf + 1;
    create_tree(lf,st,md);
    create_tree(rg,md + 1,ed);
    tree[node] = tree[lf] + tree[rg];
    prop[node] = 0;
    return ;
}

void update(int node,int st,int ed,int i,int j,int v)
{
    if(st > j || ed < i)
        return ;
    if(st>=i && ed <=j)
    {
        prop[node] +=v;
        tree[node] += (ed - st +1)*v;
        return ;
    }
    int md = (st + ed)/2;
    int lf = 2 * node;
    int rg = lf + 1;
    update(lf,st,md,i,j,v);
    update(rg,md + 1,ed,i,j,v);
    tree[node] = tree[lf] + tree[rg] + (ed - st + 1)*v;///(ed-st+1)*v eita add kora hoise cz onk gula upadte thakle oigula jate uodate hoie upore uthe
}

int query(int node,int st,int ed,int i,int j,int carry =0)
{
    if(st > j ||ed < i)
        return 0;
    if(st >= i && ed<=j)
    {
        return tree[node] + carry*(ed - st + 1);
    }
    int md = (st + ed )/2;
    int lf = 2 * node;
    int rg = 1 + lf;
    int a = query(lf,st,md,i,j,prop[node]+carry);
    int b = query(rg,md+1,ed,i,j,prop[node]+carry);
    return  tree[node] = a + b;

}
int main()
{
   cin>>n;
   for(int i=0; i<n; i++)
        cin >> A[i];
       create_tree(1,0,n-1);
}
