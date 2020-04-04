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

signed main(){
    FASTER;
    int t;cin>>t;
    for(int T=1;T<=t;T++){
        
        int n;cin>>n;
        vector<tuple<int,int,int>> v(n);
        vi s,e;
        vi ans(n,0);
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            s.push_back(a);
            e.push_back(b);
            get<0>(v[i])=a;
            get<1>(v[i])=b;
            get<2>(v[i])=i;//1 C, 2 J, 0 none
        }
        sort(all(v));
        sort(all(s));
        sort(all(e));
        
        for(int i=0;i<n;i++){
            if(ans[get<2>(v[i])])continue;
            int s=get<0>(v[i]);
            int e=get<1>(v[i]);
            ans[get<2>(v[i])]=1;
            
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int ss=get<0>(v[j]);
                int ee=get<1>(v[j]);
                int ff=get<2>(v[j]);
                if(ss>=e || ee<=s)continue;
                ans[ff]=2;
            }
        }
        
        string finAns="";
        for(int i:ans){
            if(i==2)finAns+="J";
            else if(i==1)finAns+="C";
        }
        
        bool ok=1;
        for(int i=1;i<=24*60 && ok;i++){
            int cnt=0;
            cnt+=s.end()-lower_bound(all(s),i);
            auto it=lower_bound(all(e),i);
            if(it!=e.begin()){
                it--;
                cnt+=it-e.begin()+1;
            }
            ok&=(n-cnt<=2);
        }
        
        cout<<"Case #"<<T<<": "<<(ok?finAns:"IMPOSSIBLE")<<"\n";
    }
}
