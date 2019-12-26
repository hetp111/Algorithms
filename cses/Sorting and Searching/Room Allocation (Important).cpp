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
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

signed main(){
    FASTER;
    int n;cin>>n;
    set<pair<pii,int>> mp;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        mp.insert({{a,b},i});
    }
    multiset<pii> q;
    int k=0;
    vi ans(n);
    for(const pair<pii,int> &p:mp){
        int s=p.first.first;
        int e=p.first.second;
        if(q.empty() || (q.begin()->first)>=s){
            k++;
            q.insert({e,k});
            ans[p.second]=k;
        }else{
            ans[p.second]=q.begin()->second;
            q.insert({e,ans[p.second]});
            q.erase(q.begin());
        }
    }
    cout<<k<<"\n"<<ans;
}