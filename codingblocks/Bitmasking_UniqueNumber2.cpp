#include <bits/stdc++.h>
using namespace std;
//https://hack.codingblocks.com/contests/c/52/463
//;)
main(){
    int n;cin>>n;
    int ans,tmp,arr[n];cin>>tmp;
    ans=tmp;arr[0]=tmp;
    for(int i=1;i<n;i++){
        cin>>tmp;
        arr[i]=tmp;
        ans=ans^tmp;
    }
    int rightmostsetbitIndex=0;
    while(ans>0){
        if(ans&1){rightmostsetbitIndex++;break;}
        ans=ans>>1;
    }
    int ans1,ans2,first=1,first2=1;
    for(int i=0;i<n;i++){
        if((arr[i]>>(rightmostsetbitIndex-1))&1){
            if(first==1){first=0;ans1=arr[i];}
            else ans1^=arr[i];
        }else{
            if(first2==1){first2=0;ans2=arr[i];}
            else ans2^=arr[i];
        }
    }
    cout<<min(ans1,ans2)<<" "<<max(ans1,ans2);
}
