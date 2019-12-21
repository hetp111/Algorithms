//You need to find the the maximum value of x, such that, n! % kx = 0.

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

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        map<int,int> factsOfKWithFreq;
        
        for(int i=2;i*i<=k;i++){//k and not K, it's fine
            int cnt=0;
            while(k%i==0){
                k/=i;
                cnt++;
            }
            if(cnt)factsOfKWithFreq[i]=cnt;
        }
        if(k!=1)factsOfKWithFreq[k]=1;
        
        int ans=INF;
        
        for(const pii &p:factsOfKWithFreq){
            int pr=p.first;
            int cntOfPrInNf=0;
            int i=pr;
            while(n/i){
                cntOfPrInNf+=(n/i);
                i=i*pr;
            }
            ans=min(ans,cntOfPrInNf/p.second);
        }
        cout<<ans<<"\n";
    }
}