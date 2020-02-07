//https://codeforces.com/contest/1144/submission/70517818
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
string a,b;
vi x,y;

vi add(vi x,vi y){
    for(int i=n;i>=0;i--){
        x[i]+=y[i];
        if(i){
            x[i-1]+=(x[i]/26);
            x[i]%=26;
        }
    }
    return x;
}

vi div(vi x){
    for(int i=0;i<=n;i++){
        int r=x[i]%2;
        x[i]/=2;
        if(i<=n-1)x[i+1]+=r*26;
    }
    return x;
}

signed main(){
    FASTER;
    cin>>n>>a>>b;
    x.push_back(0);
    y.push_back(0);
    for(const char &c:a)x.push_back(c-'a');
    for(const char &c:b)y.push_back(c-'a');
    x=add(x,y);//base26
    x=div(x);
    for(int i=1;i<=n;i++)cout<<char(x[i]+'a');
}

 