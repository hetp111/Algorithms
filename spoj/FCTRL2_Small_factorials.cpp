#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

void mul(vector<int> &v, int &n, int no){
    int rem=0;
    for(int i=0;i<n;i++){
        int product=v[i]*no+rem;
        v[i]=product%10;
        rem=product/10;
    }
    while(rem){
        v[n]=rem%10;
        rem/=10;
        n++;
    }
}

void big_f(int num){
    vector<int> v(1000,0);
    v[0]=1;
    int n=1;//size indx

    for(int i=2;i<=num;i++)mul(v,n,i);//note pass by ref

    for(int i=n-1;i>=0;i--)cout<<v[i];

}

int main(){
    FASTER;
    int t,n;cin>>t;
    while(t--){
        cin>>n;
        big_f(n);
        cout<<"\n";
    }
}
