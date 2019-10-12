#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD 1000000007
#define eps 1e-8
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

int poww(int a,int b){
    if(b==0)return 1;
    int p=poww(a,b/2);
    p=(p*p)%MOD;
    if(b&1)p=(p*a)%MOD;
    return p;
}

struct node{
    int data,lz;
};

node tree[800000];

void lzUpdate(int indx,int s,int e){
    if(tree[indx].lz!=-1){
        tree[indx].data=(poww(2,e-s+1)-1)*tree[indx].lz;
        if(s!=e){
            tree[indx*2+1].lz=tree[indx].lz;
            tree[indx*2+2].lz=tree[indx].lz;
        }
        tree[indx].lz=-1;
    }
}

void update(int s,int e,int indx,int l,int r,int val){
    lzUpdate(indx,s,e);
    if(s>r || e<l)return;
    if(s>=l && e<=r){
        tree[indx].data=(poww(2,e-s+1)-1)*val;
        if(s!=e){
            tree[indx*2+1].lz=val;
            tree[indx*2+2].lz=val;
        }
        return;
    }
    int mid=(s+e)/2;
    update(s,mid,indx*2+1,l,r,val);
    update(mid+1,e,indx*2+2,l,r,val);
    
    tree[indx]={((tree[indx*2+1].data*poww(2,e-mid))%MOD+(tree[indx*2+2].data))%MOD,-1};
}

int query(int s,int e,int indx,int l,int r){
    lzUpdate(indx,s,e);
    if(s>r || e<l)return 0;
    if(s>=l && e<=r)return tree[indx].data;
    int mid=(s+e)/2;
    int aa=query(s,mid,indx*2+1,l,r);
    int bb=query(mid+1,e,indx*2+2,l,r);
    
    //return ((aa*poww(2,e-mid))%MOD+bb)%MOD;
    if(r<=mid)return aa;
    return ((aa*poww(2,min(e,r)-mid))%MOD+bb)%MOD;
}

signed main(){
    FASTER;
    for(int i=0;i<800000;i++){
        tree[i]={0,-1};
    }
    int n,m;cin>>n>>m;
    while(m--){
        int a,l,r;cin>>a>>l>>r;
        int s=0,e=n-1,indx=0;
        if(a==0 || a==1){
            update(s,e,indx,l,r,a);
        }else{
            cout<<query(s,e,indx,l,r)<<"\n";
        }
    }
}
