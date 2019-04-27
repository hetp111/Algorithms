//Carefully Crafted by hetp111
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

//bool f(pair<int,int> a, pair<int,int> b){
//    if(a.first==b.first){
//        return a.second>=b.second;
//    }
//    return a.first<b.first;
//}

//// this is an strucure which implements the
//// operator overlading
//struct CompareHeight {
//    bool operator()(Person const& p1, Person const& p2)
//    {
//        // return "true" if "p1" is ordered
//        // before "p2", for example:
//        return p1.height < p2.height;
//    }
//};

struct f{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        if(a.first==b.first){
            return a.second>=b.second;
        }
        return a.first<b.first;
    }
};

signed main(){
    FASTER;
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;// me0 she1
        vector<pair<int,int> > A(a),B(b);
        priority_queue<pair<int,int>, vector<pair<int,int> >, f> C;
        for(int i=0;i<a;i++){
            int tmp;cin>>tmp;
            A[i]={tmp,0};
            C.push(A[i]);
        }
        for(int i=0;i<b;i++){
            int tmp;cin>>tmp;
            B[i]={tmp,1};
            C.push(B[i]);
        }
//        while(C.size()!=1){
//            cout<<C.top().first<<" "<<C.top().second<<"\n";
//            C.pop();
//        }
        if(C.top().second==1){
            cout<<"MechaGodzilla\n";
        }else{
            cout<<"Godzilla\n";
        }
    }
}
