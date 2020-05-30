#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD (1000000007)
#define MOD2 (998244353)
#define MOD3 (1000000009)
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
ifstream cinn("in.txt");ofstream coutt("out.txt");
int poww(const int &a,int b,const int &m=MOD){if(b==0)return 1;int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;}
int ceil(const int &a,const int &b){return (a-1)/b+1;}
//Read:
//Use __builtin_popcountll for ll

int n;
vi v(1000000);
vii tree(4000000);

void buildTree(int s,int e,int idx){
    if(s==e){
        tree[idx]={v[s],s};
        return;
    }
    int mid=(s+e)/2;
    buildTree(s,mid,idx*2+1);
    buildTree(mid+1,e,idx*2+2);
    if(tree[idx*2+1].first>tree[idx*2+2].first)tree[idx]=tree[idx*2+1];
    else tree[idx]=tree[idx*2+2];
}

pii getMAXid(int s,int e,int idx,int S,int E){
    if(s>E || e<S)return {-INF,-INF};
    if(s>=S && e<=E)return tree[idx];
    int mid=(s+e)/2;
    pii a=getMAXid(s,mid,idx*2+1,S,E);
    pii b=getMAXid(mid+1,e,idx*2+2,S,E);
    if(a.first>b.first)return a;
    return b;
}

int getmax(int l,int r){
    if(l>r)return 0;
    int mid=getMAXid(0,n-1,0,l,r).second;
    return getmax(l,mid-1)+getmax(mid+1,r)+v[mid]*(r-mid+1)*(mid-l+1);
}

signed main(){
    FASTER;
    cin>>n;
    for(int i=0;i<n;i++)cin>>v[i];
    buildTree(0,n-1,0);
    int a=getmax(0,n-1);
    for(int i=0;i<n;i++)v[i]*=-1;
    buildTree(0,n-1,0);
    int b=-getmax(0,n-1);
    cout<<abs(a-b);
}