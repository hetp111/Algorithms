//https://atcoder.jp/contests/abc174/submissions/15653094
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
#define MOD2 998244353
#define MOD3 1000000009
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("in.in");ofstream coutt("out.out");
int poww(const int &a,int b,const int &m=MOD){if(b==0)return 1;int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;}
int ceil(const int &a,const int &b){return (a+b-1)/b;}
////Read:
//Check corner cases, n==1;
//
////Some function:
//__builtin_popcountll(), is_sorted(),

vi tree[4*500005];
int n,q;
int v[500005],b[500005],lst[500005];

void build(int s,int e,int idx,int S,int E){
    if(e<S || s>E)return;
    if(s==e){
        tree[idx].push_back(b[s]);
        return;
    }
    int mid=(s+e)/2;
    build(s,mid,idx*2+1,S,E);
    build(mid+1,e,idx*2+2,S,E);
    
    int i=0,j=0;
    const vi &a=tree[2*idx+1];
    const vi &b=tree[2*idx+2];
    vi &c=tree[idx];
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j])c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }
    while(i<a.size())c.push_back(a[i++]);
    while(j<b.size())c.push_back(b[j++]);
}

int get(int s,int e,int idx,int S,int E){
    if(e<S || s>E)return 0;
    if(s>=S && e<=E)return tree[idx].end()-upper_bound(all(tree[idx]),E);
    int mid=(s+e)/2;
    return get(s,mid,idx*2+1,S,E)+get(mid+1,e,idx*2+2,S,E);
}

signed main(){
    FASTER;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]--;
        lst[i]=INF;
    }
    for(int i=n-1;i>=0;i--){
        b[i]=lst[v[i]];
        lst[v[i]]=i;
    }
    build(0,n-1,0,0,n-1);
    while(q--){
        int l,r;cin>>l>>r;
        cout<<get(0,n-1,0,l-1,r-1)<<"\n";
    }
}
