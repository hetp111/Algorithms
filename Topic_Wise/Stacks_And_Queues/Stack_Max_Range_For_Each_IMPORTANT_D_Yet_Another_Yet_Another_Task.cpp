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
////Read:
//Use __builtin_popcountll for ll;
//Check corner cases, n==1;
//
////Some function:
//__builtin_popcountll(), 

int n,v[100005],pre[100005],suf[100005],Lc[100005],Rc[100005];

signed main(){
    FASTER;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)pre[i]=v[i]+pre[i-1];
    for(int i=n;i>=1;i--)suf[i]=v[i]+suf[i+1];
    
    stack<int> stk;
    for(int i=1;i<=n;i++){
        while(!stk.empty() && v[stk.top()]<=v[i]){
            int tp=stk.top();
            int sum=pre[i-1]-pre[tp-1];
            Lc[i]=max({Lc[i],sum,sum+Lc[tp]});
            stk.pop();
        }
        stk.push(i);
    }
    
    stk=stack<int>();
    for(int i=n;i>=1;i--){
        while(!stk.empty() && v[stk.top()]<=v[i]){
            int tp=stk.top();
            int sum=suf[i+1]-suf[tp+1];
            Rc[i]=max({Rc[i],sum,sum+Rc[tp]});
            stk.pop();
        }
        stk.push(i);
    }
    
    int ans=-INF;
    for(int i=1;i<=n;i++){
        ans=max(ans,Lc[i]+Rc[i]);
    }
    cout<<ans;
}