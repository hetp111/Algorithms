//Exp val.
//https://atcoder.jp/contests/dp/tasks/dp_j
//https://codeforces.com/blog/entry/64250?#comment-523543
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

int n;
int fr[4];
double pdp[301][301][301];

double f(int one,int two,int three){
    if(one<0 || two<0 || three<0)return 0;
    if(one==0 && two==0 && three==0)return 0;
    double &ans=pdp[one][two][three];
    
    if(ans>=0)return ans;
    double k= (one+two+three);
    ans=0;
    ans+=(f(one,two+1,three-1)*(1.0*three/k));
    ans+=(f(one+1,two-1,three)*(1.0*two/k));
    ans+=(f(one-1,two,three)*(1.0*one/k));
    ans+=(n/k);
    return ans;
}

signed main(){
    FASTER;
    memset(pdp,-1,sizeof pdp);
    
    cin>>n;
    for(int i=0;i<n;i++){
        int in;cin>>in;
        fr[in]++;
    }
    cout<<fixed<<setprecision(10)<<f(fr[1],fr[2],fr[3]);
}
