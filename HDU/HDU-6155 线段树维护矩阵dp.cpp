#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
const int N = 1e5+5;
const int msize = 3;
int n,q;

struct Matrix
{
    ll v[msize][msize];
    friend Matrix operator * (const Matrix &a,const Matrix &b)
    {
        Matrix c;
        for(int i = 0;i < msize;i++)
            for(int j = 0;j < msize;j++)
            {
                c.v[i][j] = 0;
                for(int k = 0;k < msize;k++)
                    c.v[i][j] = (c.v[i][j] + (a.v[i][k] * b.v[k][j] % MOD))%MOD;
            }
        return c;
    }
};
const Matrix m[2] = {{1, 0, 0, 1, 1, 0, 1, 0, 1}, {1, 1, 0, 0, 1, 0, 0, 1, 1}};
Matrix data[N<<2];
bool flip[N<<2];
char str[N];


void mat_flip(Matrix &mat)
{
    swap(mat.v[0][0],mat.v[0][1]);
    swap(mat.v[1][0],mat.v[1][1]);
    swap(mat.v[2][0],mat.v[2][1]);
    swap(mat.v[0][0],mat.v[1][0]);
    swap(mat.v[0][1],mat.v[1][1]);
}
void push_down(int o)
{
    if(flip[o])
    {
        flip[o<<1] ^= flip[o];
        flip[o<<1|1] ^= flip[o];
        mat_flip(data[o<<1]);
        mat_flip(data[o<<1|1]);
        flip[o] = false;
    }
}
void build(int o,int l,int r)
{
    if(l == r)
        data[o] = m[str[l] - '0'];
    else
    {
        int mid = (l+r)>>1;
        build(o<<1,l,mid);
        build(o<<1|1,mid+1,r);
        data[o] = data[o<<1]*data[o<<1|1];
    }
    flip[o] = false;
}
void update(int o,int l,int r,int ql,int qr)
{
    if(ql <= l && r <= qr)
    {
        flip[o] ^= 1;
        mat_flip(data[o]);
        return;
    }

    if(r < ql || qr< l)
        return;
    int mid = (l+r)>>1;
    push_down(o);
    update(o<<1,l,mid,ql,qr);
    update(o<<1|1,mid+1,r,ql,qr);
    data[o] = data[o<<1]*data[o<<1|1];
}
Matrix query(int o,int l,int r,int ql,int qr)
{
    if(ql <= l && r <= qr)
        return data[o];
    if(r < ql || qr< l)
        return {1, 0, 0, 0, 1, 0, 0, 0, 1};
    int mid = (l+r)>>1;
    push_down(o);
    return query(o<<1,l,mid,ql,qr)*query(o<<1|1,mid+1,r,ql,qr);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        scanf("%s",str+1);
        build(1,1,n);
        while(q--)
        {
            int type,l,r;
            scanf("%d%d%d",&type,&l,&r);
            if(type == 1)
                update(1,1,n,l,r);
            else
            {
                Matrix mat = query(1,1,n,l,r);
                printf("%lld\n",(mat.v[2][0] + mat.v[2][1])%MOD);
            }
        }
    }
    return 0;
}
