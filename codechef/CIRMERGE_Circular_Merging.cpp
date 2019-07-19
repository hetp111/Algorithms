#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define pii pair<int,int>
#define prec(n) fixed<<setprecision(n)
#define MOD 1000000007
#define eps 1e-8
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){
    return out<<"("<<a.first<<","<<a.second<<")";}
template<class A> ostream& operator<<(ostream& out, const vector<A> &a){
	out<<"";for(auto it=a.begin();it!=a.end();it++){if(it!=a.begin())out<<" ";out<<*it;}out<<"";
	return out;}
template<class A, class B> istream& operator>>(istream& in, pair<A,B> &a){in>>a.first>>a.second;return in;}
template<class A> istream& operator>>(istream& in, vector<A> &a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");


vi v;
vi pref;
int n,dp[800][800];

int sum(int i,int j){
    if(i==0)return pref[j];
    return pref[j]-pref[i-1];
}

int f(int i,int j){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=1e18;
    for(int k=i;k<j;k++){
        ans=min(ans,f(i,k)+f(k+1,j)+sum(i,k)+sum(k+1,j));
    }
    dp[i][j]=ans;
    return ans;
}

void solve(){
    cin>>n;
    v.resize(n);
    pref.resize(2*n);
    cin>>v;
    memset(dp,-1,sizeof(dp));

    for(int i=0;i<n;i++)v.push_back(v[i]);

    pref[0]=v[0];
    for(int i=1;i<2*n;i++)pref[i]=pref[i-1]+v[i];

    int ans=1e18;
    for(int i=0;i<n;i++)ans=min(ans,f(i,i+n-1));

    cout<<ans<<"\n";
}

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--)solve();
}
