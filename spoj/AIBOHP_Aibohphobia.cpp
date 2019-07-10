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

string s;
int n,dp[6100][6100];

bool isp(int i,int j){
    while(i<=j){
        if(s[i]==s[j])i++,j--;
        else return false;
    }
    return true;
}

int f(int i,int j){
    if(isp(i,j))return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int a,b,ans;
    if(s[i]==s[j]){
        ans=f(i+1,j-1);
    }else{
        a=f(i+1,j);
        b=f(i,j-1);
        ans=min(a,b)+1;
    }
    dp[i][j]=ans;
    return ans;
}

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>s;n=s.size();
        cout<<f(0,n-1)<<"\n";
    }
}
