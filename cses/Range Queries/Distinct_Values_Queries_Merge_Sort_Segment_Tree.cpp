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

//v[i] is the pos of next occurrence of vv[i] 

int n,q;
vi tree[4*200005];
int vv[200005],v[200005];

vi meraMerge(const vi &a,const vi &b){
    vi ans;
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans.push_back(a[i++]);
        }else{
            ans.push_back(b[j++]);
        }
    }
    
    while(i<a.size()){
        ans.push_back(a[i++]);
    }
    while(j<b.size()){
        ans.push_back(b[j++]);
    }
    return ans;
}

void buildIt(int s,int e,int indx){
    if(s==e){
        tree[indx]=vi(1,v[e]);
        return;
    }
    int mid=(s+e)/2;
    buildIt(s,mid,indx*2);
    buildIt(mid+1,e,indx*2+1);
    tree[indx]=meraMerge(tree[indx*2],tree[indx*2+1]);
}

int queryy(int s,int e,int indx,int l,int r){
    if(s>r || e<l)return 0;
    if(s>=l && e<=r)return tree[indx].end()-upper_bound(all(tree[indx]),r);
    int mid=(s+e)/2;
    return queryy(s,mid,indx*2,l,r)+queryy(mid+1,e,indx*2+1,l,r);
}

signed main(){ 
    FASTER;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>vv[i];
    
    map<int,int> last;
    for(int i=n;i>=1;i--){
        if(last[vv[i]]==0){
            v[i]=INF;
        }else{
            v[i]=last[vv[i]];
        }
        last[vv[i]]=i;
    }
    
    buildIt(1,n,1);
    
    while(q--){
        int l,r;cin>>l>>r;
        cout<<queryy(1,n,1,l,r)<<"\n";
    }
}
