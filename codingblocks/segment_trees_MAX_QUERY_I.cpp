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
    vector<int> vec;
};

void mergee(int indx, vector<node> &tree){
    int l=0,r=0;
    vector<int> &left=tree[indx*2+1].vec;
    vector<int> &right=tree[indx*2+2].vec;
    vector<int> &diss=tree[indx].vec;
    while(l<left.size() && r<right.size()){
        if(left[l]<right[r]){
            diss.push_back(left[l]);
            l++;
        }else{
            diss.push_back(right[r]);
            r++;
        }
    }
    while(l<left.size()){
        diss.push_back(left[l]);l++;
    }
    while(r<right.size()){
        diss.push_back(right[r]);r++;
    }
}

void makeTree(int s,int e,int indx,const vi &v,vector<node> &tree){
    if(s==e){
        tree[indx].vec={v[s]};
        return;
    }
    int mid=(s+e)/2;
    makeTree(s,mid,indx*2+1,v,tree);
    makeTree(mid+1,e,indx*2+2,v,tree);
    mergee(indx,tree);
    return;
}

int bin(const vector<int> &v, int k){
    auto it = lower_bound(all(v),k);
    auto it0 = v.end();
    return it0-it;
}

int query(int l,int r,int k,int s,int e,int indx,const vector<node> &tree){
    if(r<s || l>e){
        return 0;
    }
    if(l<=s && r>=e){
        return bin(tree[indx].vec,k);
    }
    int mid=(s+e)/2;
    int left=query(l,r,k,s,mid,indx*2+1,tree);
    int right=query(l,r,k,mid+1,e,indx*2+2,tree);
    return left+right;
}

signed main(){
    FASTER;
    int n;cin>>n;
    vi v(n);cin>>v;
    int q;cin>>q;
    vector<node> tree(4*n);
    makeTree(0,n-1,0,v,tree);//s e indx v tree
    while(q--){
        int l,r,k;cin>>l>>r>>k;l--;r--;
        cout<<query(l,r,k,0,n-1,0,tree)<<"\n";
    }
}
