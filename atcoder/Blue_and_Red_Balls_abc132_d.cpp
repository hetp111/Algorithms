//https://atcoder.jp/contests/abc132/tasks
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

int nCrdp[2001][2001];

void nCr(){
    for(int i=0;i<=2000;i++)nCrdp[i][i]=1,nCrdp[i][0]=1;
    for(int i=1;i<=2000;i++){
        for(int j=i+1;j<=2000;j++){//j>i
            nCrdp[j][i]=(nCrdp[j-1][i-1]+nCrdp[j-1][i])%MOD;
        }
    }
}

signed main(){
    FASTER;
    nCr();
    int n,k;cin>>n>>k;
    int b,r;b=k,r=n-k;
    for(int i=1;i<=k;i++)
    cout<<(nCrdp[b-1][i-1]*nCrdp[r+1][i])%MOD<<"\n";
}
