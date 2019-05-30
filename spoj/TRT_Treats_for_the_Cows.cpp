#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){
    return out<<"("<<a.first<<", "<<a.second<<")";}
template<class A> ostream& operator<<(ostream& out, const vector<A> &a){
	out<<"[";for(auto it=a.begin();it!=a.end();it++){if(it!=a.begin())out<<",";out<<*it;}cout<<"]";
	return out;}
template<class A, class B> istream& operator>>(istream& in, pair<A,B> &a){in>>a.first>>a.second;return in;}
template<class A> istream& operator>>(istream& in, vector<A> &a){for(A &i:a)in>>i;return in;}

//rec + memo solution, try dp

vector<vi> dp(3000,vi(3000,-1));

int maxf(const vi &v,int l,int r,int cnt){
    if(cnt==v.size()+1)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int c1=cnt*v[l]+maxf(v,l+1,r,cnt+1);
    int c2=cnt*v[r]+maxf(v,l,r-1,cnt+1);
    dp[l][r]=max(c1,c2);
    return dp[l][r];
}

signed main(){
    FASTER;
    int n;cin>>n;
    vi v(n);cin>>v;
    cout<<maxf(v,0,n-1,1);
}
