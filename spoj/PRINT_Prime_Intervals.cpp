#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD 1000000007
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

vi prime;

bool ispr(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return 0;
    }
    return 1;
}

void solve(){
    int l,r;cin>>l>>r;
    int pr[r-l+1];
    memset(pr,1,sizeof pr);
    
    for(const int &p:prime){
        int st=(l/p)*p + p*(l%p!=0);//ceil
        for(int i=st;i<=r;i+=p){
            if(i!=p)pr[i-l]=0;
        }
    }
    
    for(int i=0;i<r-l+1;i++){
        if(pr[i])cout<<i+l<<"\n";
    }
    
}

signed main(){
    FASTER;
    for(int i=2;i<=sqrt(2147483648);i++)if(ispr(i))prime.push_back(i);
    
    int t;cin>>t;
    while(t--){
        solve();
    }
    
}
