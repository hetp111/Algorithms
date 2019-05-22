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

void buildTree(int s,int e,int indx,const vi &v,vi &tree){
    if(s==e){
        tree[indx]=v[s];
        return;
    }
    int mid=(s+e)/2;
    buildTree(s,mid,2*indx+1,v,tree);
    buildTree(mid+1,e,2*indx+2,v,tree);
    tree[indx]=min(tree[indx*2+1],tree[indx*2+2]);
    return;
}

int printQ(int SS,int EE,int s,int e,int indx,const vi &tree){
    if(SS>=s && EE<=e){
        return tree[indx];
    }
    if(s>EE || e<SS)return INT_MAX;
    int mid=(SS+EE)/2;
    int lFt=printQ(SS,mid,s,e,indx*2+1,tree);
    int rht=printQ(mid+1,EE,s,e,indx*2+2,tree);
    return min(lFt,rht);
}

void update(int id, int num, int indx, int s, int e, vi &tree){
    if(s==e && id==e){
        tree[indx]=num;
        return;
    }
    if(!(id>=s && id<=e)){
        return;
    }
    int mid=(s+e)/2;
    update(id,num,indx*2+1,s,mid,tree);
    update(id,num,indx*2+2,mid+1,e,tree);
    tree[indx]=min(tree[indx*2+1],tree[indx*2+2]);
    return;
}

signed main(){
    FASTER;
    int n,q;cin>>n>>q;
    vi v(n),tree(4*n);cin>>v;
    buildTree(0,n-1,0,v,tree);

    while(q--){
        int a;cin>>a;
        if(a==1){
            int l,r;cin>>l>>r;
            cout<<printQ(0,n-1,l-1,r-1,0,tree)<<"\n";
        }else{
            int id,num;cin>>id>>num;
            update(id-1,num,0,0,n-1,tree);
        }
    }
}
