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

signed main(){
    FASTER;
    int n;cin>>n;
    vi v(n);cin>>v;
    vector<vi> dp(n,vi(n));
    int year=n;
    for(int i=0;i<n;i++)dp[i][i]=year*v[i];
    year--;

    for(int len=1;len<n;len++){
        int r=0,c=len;
        int cntr=year;
        while(cntr--){
            int A=year*v[r]+dp[r+1][c];
            int B=year*v[c]+dp[r][c-1];
            dp[r][c]=max(A,B);
            r++;
            c++;
        }
        year--;
    }
    cout<<dp[0][n-1];
}
