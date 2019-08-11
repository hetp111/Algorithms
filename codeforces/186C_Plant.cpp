//https://codeforces.com/problemset/problem/186/C
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

vector<vi> T={{2,1},{0,4}};

vector<vi> multi(const vector<vi> &a,const vector<vi> &b){
    int r1=a.size(),c1=a[0].size();
    int c2=b[0].size();

    vector<vi> c(r1,vi(c2,0));

    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            for(int k=0;k<c2;k++){
                c[i][k]=(c[i][k]%MOD+((a[i][j]%MOD)*(b[j][k]%MOD))%MOD)%MOD;
            }
        }
    }
    return c;
}

vector<vi> poww(int n){
    if(n==0){
        vector<vi> v={
            {1,0},
            {0,1},
        };
        return v;
    }
    vector<vi> p=poww(n/2);
    vector<vi> ans=multi(p,p);
    if(n&1){
        ans=multi(ans,T);
    }
    return ans;
}

signed main(){
    FASTER;
    int i;cin>>i;
    vector<vi> Timinus1=poww(i);
    vector<vi> F1={{1},{1}};
    vector<vi> anss=multi(Timinus1,F1);
    cout<<anss[0][0];
}
