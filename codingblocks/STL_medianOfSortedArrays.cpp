#include <bits/stdc++.h>
using namespace std;
//MEDIAN OF SORTED ARRAYS
//https://hack.codingblocks.com/contests/c/52/422
int main() {//;)
    int n;cin>>n;
    vector<int> v(2*n);
    for(int i=0;i<2*n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    cout<<v[n-1];
}
