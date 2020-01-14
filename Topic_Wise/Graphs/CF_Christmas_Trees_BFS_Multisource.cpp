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

//sexy

signed main(){
    FASTER;
    int n,m;cin>>n>>m;
    
    deque<int> dq;
    map<int,int> dis;
    
    for(int i=0;i<n;i++){
        int in;cin>>in;
        dis[in]=0;
        dq.push_back(in);
    }
    
    int sumMin=0;
    vi ans;
    
    while(!dq.empty()){
        int cur = dq.front();dq.pop_front();
        if(dis[cur]!=0){
            sumMin+=dis[cur];
            ans.push_back(cur);
        }
        if(dis.find(cur-1)==dis.end()){
            dis[cur-1]=dis[cur]+1;
            dq.push_back(cur-1);
        }
        if(dis.find(cur+1)==dis.end()){
            dis[cur+1]=dis[cur]+1;
            dq.push_back(cur+1);
        }
        if(ans.size()==m)break;
    }
    
    cout<<sumMin<<'\n'<<ans;
    
}