//Vivekanand_Khyade
#include<bits/stdc++.h>
using namespace std;

main(){
    vector<int> minStepsTo,input,fromWhere;
    int n;cin>>n;int N=n;
    minStepsTo.resize(n);
    fromWhere.resize(n);
    minStepsTo[0]=0;
    fromWhere[0]=0;
    while(n--){
        int tmp;cin>>tmp;input.push_back(tmp);
    }
    int j=0;
    for(int i=1;i<N;i++){
        for(j=0;j<i;j++){
            if(i-j<=input[j]){
                if(i==1){minStepsTo[i]=1;break;}
                minStepsTo[i]=(1+minStepsTo[j]);
                break;
            }
        }
        fromWhere[i]=j;
    }

    for(int iii:minStepsTo){
        cout<<iii<<" ";
    }
    cout<<"\n";
    for(int iii:fromWhere){
        cout<<iii<<" ";
    }
}
