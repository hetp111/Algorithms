//https://www.spoj.com/problems/DSUBSEQ/

//https://codinghangover.wordpress.com/2013/12/10/spoj-dsubseq-distinct-subsequences/

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
string s;

signed main() {
    FASTER;
    int t;cin>>t;
    while(t--){
        cin>>s;
        n=s.size();
        vi dp(n+1),lst(26,-1);
        dp[0]=1;
        
        for(int i=1;i<=n;i++){
            dp[i]=(dp[i-1]*2)%MOD;
            if(lst[s[i-1]-'A']!=-1){
                dp[i]=(dp[i]-dp[lst[s[i-1]-'A']-1]+MOD)%MOD;
            }
            lst[s[i-1]-'A']=i;
        }
        
        cout<<dp[n]<<"\n";
    }
}