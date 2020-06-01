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
#define MOD2 (998244353)
#define MOD3 (1000000009)
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
ifstream cinn("in.txt");ofstream coutt("out.txt");
int poww(const int &a,int b,const int &m=MOD){if(b==0)return 1;int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;}
int ceil(const int &a,const int &b){return (a-1)/b+1;}
////Read:
//Use __builtin_popcountll for ll;
//Check corner cases, n==1;
//
////Some function:
//__builtin_popcountll(), 

int n;
vi v,lc,rc;

int getMAX(){
    stack<int> stk;
    for(int i=0;i<n;i++){
        while(!stk.empty() && v[stk.top()]<=v[i]){
            lc[i]+=lc[stk.top()]+1;
            stk.pop();
        }
        stk.push(i);
    }
    stk=stack<int>();
    for(int i=n-1;i>=0;i--){
        while(!stk.empty() && v[stk.top()]<v[i]){
            rc[i]+=rc[stk.top()]+1;
            stk.pop();
        }
        stk.push(i);
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(lc[i]+1)*(rc[i]+1)*v[i];
    }
    
    return ans;
}

signed main(){
    FASTER;
    cin>>n;
    v=lc=rc=vi(n,0);
    for(int &i:v)cin>>i;
    int a=getMAX();
    for(int &i:v)i*=-1;
    lc=rc=vi(n,0);
    int b=-getMAX();
    cout<<a-b;
}