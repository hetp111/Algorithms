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

struct BIT{
    int bit[200005];
    void update(int indx,int val){
        while(indx<=200000){
            bit[indx]+=val;
            indx+=(indx&-indx);
        }
    }
    int get(int indx){
        int sum=0;
        while(indx>0){
            sum+=bit[indx];
            indx-=(indx&-indx);
        }
        return sum;
    }
}A,B;

signed main(){
    int n;cin>>n;
    vii v(n);
    set<int> st;
    for(int i=0;i<n;i++)cin>>v[i].first;
    for(int i=0;i<n;i++){
        cin>>v[i].second;
        st.insert(v[i].second);
    }
    
    map<int,int> mp;
    int k=0;
    for(const auto &pp:st)mp[pp]=++k;
    for(auto &pp:v)pp.second=mp[pp.second];
    
    sort(all(v));
    
    int ans=0;
    for(int i=0;i<n;i++){
        int chote = A.get(v[i].second);
        int posSum = B.get(v[i].second);
        ans += chote*v[i].first-posSum;
        A.update(v[i].second,1);
        B.update(v[i].second,v[i].first);
    }
    cout<<ans;
}