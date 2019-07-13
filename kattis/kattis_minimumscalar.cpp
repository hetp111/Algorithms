#include <bits/stdc++.h>//het-
using namespace std;//https://open.kattis.com/problems/minimumscalar

main(){
    long long t;cin>>t;long long c=0;
    vector<string> ansss;
    while(t--){
        long long n;cin>>n;vector<long long> a,b;
        for(long long i=0;i<n;i++){
            long long tmp;cin>>tmp;
            a.push_back(tmp);
        }
        for(long long i=0;i<n;i++){
            long long tmp;cin>>tmp;
            b.push_back(tmp);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long long ans=0;
        for(long long i=0;i<n;i++){//a 1 2 3 b 9 8 7
            ans+=a[i]*b[n-i-1];
        }
        c++;
        ansss.push_back("Case #"+to_string(c)+": "+to_string(ans));

    }
    for(string asds:ansss){
        cout<<asds<<endl;
    }
}
