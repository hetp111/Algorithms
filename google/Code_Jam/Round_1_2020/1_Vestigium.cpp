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
        vvi v(n,vi(n));
        int tr=0,row=0,col=0;
        for(int i=0;i<n;i++){
            set<int> st;
            for(int j=0;j<n;j++){
                cin>>v[i][j];
                if(i==j)tr+=v[i][j];
                st.insert(v[i][j]);
            }
            if(st.size()!=n)row++;
        }
        for(int j=0;j<n;j++){
            set<int> st;
            for(int i=0;i<n;i++){
                st.insert(v[i][j]);
            }
            if(st.size()!=n)col++;
        }
        cout<<"Case #"<<T<<": "<<tr<<" "<<row<<" "<<col<<"\n";
    }
}
