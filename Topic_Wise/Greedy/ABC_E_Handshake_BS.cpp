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
//__builtin_popcountll(), 

int n,m;
int ans;
vi v,pre;

bool f(int sum){//min sum of 2 pair from m
    int cnt=0;
    int lo=0;
    for(int i=0;i<n;i++){
        //v[i]+x>=sum
        //x>=sum-v[i]
        int num=v.end()-lower_bound(all(v),sum-v[i]);
        cnt+=num;
        lo+=num*v[i]+pre[n-1]-(n-num-1>=0?pre[n-num-1]:0);
    }
    if(cnt>=m){
        ans=lo-(cnt-m)*sum;
        return 1;
    }
    return 0;
}

signed main(){
    FASTER;
    cin>>n>>m;
    v=vi(n);cin>>v;
    sort(all(v));
    pre=v;
    for(int i=1;i<n;i++)pre[i]+=pre[i-1];
    
    int s=2*v[0],e=2*v[n-1];
    while(s<=e){
        int mid=(s+e)/2;
        if(f(mid))s=mid+1;
        else e=mid-1;
    }
    cout<<ans;
}
