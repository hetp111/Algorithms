#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define pii pair<int,int>
#define prec(n) fixed<<setprecision(n)
#define MOD 1000000007
#define eps 1e-8
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){
    return out<<"("<<a.first<<","<<a.second<<")";}
template<class A> ostream& operator<<(ostream& out, const vector<A> &a){
	out<<"";for(auto it=a.begin();it!=a.end();it++){if(it!=a.begin())out<<" ";out<<*it;}out<<"";
	return out;}
template<class A, class B> istream& operator>>(istream& in, pair<A,B> &a){in>>a.first>>a.second;return in;}
template<class A> istream& operator>>(istream& in, vector<A> &a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

int n;
int v[100000];

int f(int k){
    deque<int> dq;
    deque<int> dq2;
    
    for(int i=0;i<k;i++){
        while(!dq.empty() && v[i]>v[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
 
        while(!dq2.empty() && v[i]<v[dq2.back()]){
            dq2.pop_back();
        }
        dq2.push_back(i);
    }
    
    for(int i=k;i<n;i++){
    
        int mx = v[dq.front()];
        int mn = v[dq2.front()];
        
        //cout<<mx<<" "<<mn<<"\n";
        
        if(mx-mn<=1){
            return 1;
        }
        
        while(!dq.empty() && v[i]>v[dq.back()]){
            dq.pop_back();
        }
        while(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }
        dq.push_back(i);
        
        while(!dq2.empty() && v[i]<v[dq2.back()]){
            dq2.pop_back();
        }
        while(!dq2.empty() && i-dq2.front()>=k){
            dq2.pop_front();
        }
        dq2.push_back(i);
    }
    return v[dq.front()]-v[dq2.front()]<=1;
}

signed main(){
    FASTER;
    cin>>n;
    for(int i=0;i<n;i++)cin>>v[i];
    
    //f(3);
    int s=2,e=n,mid,ans=1;
    while(s<=e){
        mid=(s+e)/2;
        if(f(mid)){
            s=mid+1;
            ans=mid;
        }else e=mid-1;
    }
    
    cout<<ans;
}
