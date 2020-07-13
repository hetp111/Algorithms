//https://atcoder.jp/contests/aising2020/tasks/aising2020_e
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

int f(const vector<pii> &v){
    int lst=-1;
    int spaces=0;
    multiset<int> add;
    for(auto c:v){
        spaces+=c.first-lst;
        lst=c.first;
        if(spaces>0){
            add.insert(c.second);
            spaces--;
        }else{
            if(!add.empty() && *add.begin()<c.second){
                add.erase(add.begin());
                add.insert(c.second);
            }
        }
    }
    int ans=0;
    for(int i:add)ans+=i;
    return ans;
}

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--){
        vector<pii> L,R;
        int n,ans=0;cin>>n;
        for(int i=0;i<n;i++){
            int k,l,r;cin>>k>>l>>r;k--;
            if(l>=r)L.push_back({k,l-r});      //0 1 2 3 4 5 6 7 8 9
            else R.push_back({n-(k+1)-1,r-l}); //9 8 7 6 5 4 3 2 1 0
            ans+=min(l,r);
        }
        sort(all(L),[](pii a,pii b){
             if(a.first!=b.first)return a.first<b.first;
             return a.second>b.second;
        });
        sort(all(R),[](pii a,pii b){
             if(a.first!=b.first)return a.first<b.first;
             return a.second>b.second;
        });
        cout<<ans+f(R)+f(L)<<"\n";
    }
}

