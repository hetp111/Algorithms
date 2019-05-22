#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){
    return out<<"("<<a.first<<", "<<a.second<<")";}
template<class A> ostream& operator<<(ostream& out, const vector<A> &a){
	out<<"[";for(auto it=a.begin();it!=a.end();it++){if(it!=a.begin())out<<",";out<<*it;}cout<<"]";
	return out;}
template<class A, class B> istream& operator>>(istream& in, pair<A,B> &a){in>>a.first>>a.second;return in;}
template<class A> istream& operator>>(istream& in, vector<A> &a){for(A &i:a)in>>i;return in;}

struct node{
    int totSum=0,maxSum=-INT_MAX,maxPrefix=-INT_MAX,maxSuffix=-INT_MAX;
};

void makeTree(int s,int e,int indx,const vi &v,vector<node> &tree){
    if(e==s){
        tree[indx].totSum=v[s];
        tree[indx].maxSum=v[s];
        tree[indx].maxPrefix=v[s];
        tree[indx].maxSuffix=v[s];
        return;
    }
    int mid=(s+e)/2;
    makeTree(s,mid,indx*2+1,v,tree);
    makeTree(mid+1,e,indx*2+2,v,tree);
    tree[indx].totSum=tree[indx*2+1].totSum+tree[indx*2+2].totSum;
    tree[indx].maxPrefix=max(tree[indx*2+1].maxPrefix,tree[indx*2+2].maxPrefix+tree[indx*2+1].totSum);
    tree[indx].maxSuffix=max(tree[indx*2+2].maxSuffix,tree[indx*2+1].maxSuffix+tree[indx*2+2].totSum);
    tree[indx].maxSum=max({tree[indx*2+1].maxSum,tree[indx*2+2].maxSum,tree[indx*2+1].maxSuffix+tree[indx*2+2].maxPrefix});
    return;
}

node prrrint(int l,int r,int s,int e,int indx,const vector<node> &tree){
    if(r<s || l>e){
        node lowInf;
        lowInf.maxPrefix=-INT_MAX;
        lowInf.maxSuffix=-INT_MAX;
        lowInf.maxSum=-INT_MAX;
        lowInf.totSum=-INT_MAX;
        return lowInf;
    }
    if(l<=s && r>=e){
        return tree[indx];
    }
    int mid=(s+e)/2;
    node ans;
    node left=prrrint(l,r,s,mid,indx*2+1,tree);
    node righ=prrrint(l,r,mid+1,e,indx*2+2,tree);
    ans.totSum=left.totSum+righ.totSum;
    ans.maxPrefix=max(left.maxPrefix,righ.maxPrefix+left.totSum);
    ans.maxSuffix=max(righ.maxSuffix,left.maxSuffix+righ.totSum);
    ans.maxSum=max({left.maxSum,righ.maxSum,left.maxSuffix+righ.maxPrefix});
    return ans;
}

signed main(){
    FASTER;
    int n;cin>>n;
    vi v(n);cin>>v;
    vector<node> tree(4*n);
    makeTree(0,n-1,0,v,tree);
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        node ans=prrrint(l-1,r-1,0,n-1,0,tree);
        cout<<ans.maxSum<<"\n";
    }
}
