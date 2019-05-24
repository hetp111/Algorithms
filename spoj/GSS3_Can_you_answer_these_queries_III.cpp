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
    int ans=-INT_MAX;
    int prefix=-INT_MAX;
    int suffix=-INT_MAX;
    int total=-INT_MAX;
};

void makeTree(int s,int e,int indx,const vi &v, vector<node> &tree){
    if(s==e){
        tree[indx]={v[e],v[e],v[e],v[e]};
        return;
    }
    int mid=(s+e)/2;
    makeTree(s,mid,indx*2+1,v,tree);
    makeTree(mid+1,e,indx*2+2,v,tree);
    tree[indx]={
        max({tree[indx*2+1].ans,tree[indx*2+2].ans,tree[indx*2+1].suffix+tree[indx*2+2].prefix}),
        max({tree[indx*2+1].prefix,tree[indx*2+1].total+tree[indx*2+2].prefix}),
        max({tree[indx*2+2].suffix,tree[indx*2+2].total+tree[indx*2+1].suffix}),
        tree[indx*2+1].total+tree[indx*2+2].total
    };
    return;
}

node query(int l,int r,int s,int e,int indx,const vector<node> &tree){
    if(r<s || l>e){
        node minn;
        return minn;
    }
    if(l<=s && r>=e){
        return tree[indx];
    }
    int mid=(s+e)/2;
    node left=query(l,r,s,mid,indx*2+1,tree);
    node right=query(l,r,mid+1,e,indx*2+2,tree);
    node Ans={
        max({left.ans,right.ans,left.suffix+right.prefix}),
        max({left.prefix,left.total+right.prefix}),
        max({right.suffix,right.total+left.suffix}),
        left.total+right.total
    };
    return Ans;
}

void updatee(int i,int num,int s,int e,int indx,vector<node> &tree){
    if(i<s || i>e)return;
    if(s==e && e==i){
        tree[indx]={num,num,num,num};
        return;
    }
    int mid=(s+e)/2;
    updatee(i,num,s,mid,indx*2+1,tree);
    updatee(i,num,mid+1,e,indx*2+2,tree);
    tree[indx]={
        max({tree[indx*2+1].ans,tree[indx*2+2].ans,tree[indx*2+1].suffix+tree[indx*2+2].prefix}),
        max({tree[indx*2+1].prefix,tree[indx*2+1].total+tree[indx*2+2].prefix}),
        max({tree[indx*2+2].suffix,tree[indx*2+2].total+tree[indx*2+1].suffix}),
        tree[indx*2+1].total+tree[indx*2+2].total
    };
}

signed main(){
    FASTER;
    int n;cin>>n;
    vi v(n);cin>>v;
    vector<node> tree(4*n);
    makeTree(0,n-1,0,v,tree);
    int q;cin>>q;
    while(q--){
        int x;cin>>x;
        if(x==1){
            int l,r;cin>>l>>r;l--;r--;
            cout<<query(l,r,0,n-1,0,tree).ans<<"\n";
        }else{
            int i,num;cin>>i>>num;i--;
            updatee(i,num,0,n-1,0,tree);
        }
    }
}
