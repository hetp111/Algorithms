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

int findSq(int m, int n){
    int cnt=1;
    while(m!=n){
        if(m>n){
            m-=n;
        }else{
            n-=m;
        }
        cnt++;
    }
    return cnt;
}

signed main(){
    FASTER;
    int l[2];
    int b[2];
    cin>>l[0]>>l[1]>>b[0]>>b[1];
    int ans=0;
    for(int x=l[0];x<=l[1];x++){
        for(int y=b[0];y<=b[1];y++){
            ans+=findSq(x,y);
            //cout<<x<<" "<<y<<" "<<findSq(x,y)<<"\n";
        }
    }
    cout<<ans<<"";
}