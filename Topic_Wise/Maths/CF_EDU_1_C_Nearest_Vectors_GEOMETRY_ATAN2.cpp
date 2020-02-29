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

double f(const int &a,const int &b){
    return atan2(a,b);
}

signed main(){
    FASTER;
    int n;cin>>n;
    vector<pair<double,int>> v(n);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v[i]={f(a,b),i};
    }
    sort(all(v));
    
    double ans=v[n-1].first-v[0].first;
    int x=v[0].second,y=v[n-1].second;
    
    v.push_back({2*PI+v[0].first,v[0].second});
    for(int i=0;i<n;i++){
        if(v[i+1].first-v[i].first<ans){
            ans=v[i+1].first-v[i].first;
            x=v[i].second;
            y=v[i+1].second;
        }
    }
    
    cout<<x+1<<" "<<y+1;
}