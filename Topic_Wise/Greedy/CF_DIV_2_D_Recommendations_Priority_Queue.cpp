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
//#define MOD (998244353)
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
    vii v(n);
    for(int i=0;i<n;i++)cin>>v[i].first;
    for(int i=0;i<n;i++)cin>>v[i].second;
    sort(all(v));
    
    priority_queue<int> pq;
    int i=0,sum=0,ans=0;
    
    while(i<n){
        int j=i;
        while(j<=n-1 && v[i].first==v[j].first){
            sum+=v[j].second;
            pq.push(v[j].second);
            j++;
        }
        int fo=v[i].first,to=(j>=n?fo+1:v[j].first);
        while(!pq.empty() && fo<to){
            sum-=pq.top();
            ans+=sum;
            pq.pop();
            fo++;
        }
        i=j;
    }
    while(!pq.empty()){
        sum-=pq.top();
        ans+=sum;
        pq.pop();
    }
    cout<<ans;
}
