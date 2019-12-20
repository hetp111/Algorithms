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

class node{
public:
    int first,second;
};
//https://stackoverflow.com/questions/57001655/functors-vs-comparators
class comparator{//Essentially, this means a comparator is a functor that you can use to put some numbers in the right order.
public:
    bool operator()(const node &a,const node &b){
        if(a.second==b.second)return a.first<b.first;
        return a.second<b.second;
    }
};

void solve(){
    int n,m;cin>>n>>m;
    vii adj[n+1];
    while(m--){
        int a,b,c;cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    
    int s;cin>>s;
    int dis[n+1];
    for(int i=1;i<=n;i++)dis[i]=INF;
    set<node,comparator> st;
    dis[s]=0;
    st.insert({s,0});
    
    while(!st.empty()){
        int par=(*st.begin()).first;
        int disTillNow=(*st.begin()).second;
        st.erase(st.begin());
        for(const pii &child:adj[par]){
            int cChild=child.first;
            int cDis=child.second;
            if(disTillNow+cDis>=dis[cChild])continue;
            if(st.find({cChild,dis[cChild]})!=st.end())st.erase({cChild,dis[cChild]});
            dis[cChild]=disTillNow+cDis;
            st.insert({cChild,dis[cChild]});
        }
    }
    
    for(int i=1;i<=n;i++){
        if(i!=s)cout<<(dis[i]==INF?-1:dis[i])<<" ";
    }
    cout<<"\n";
}

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--){
        solve();
    }
}