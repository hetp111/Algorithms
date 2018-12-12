//by hetp111
//https://codeforces.com/problemset/problem/158/B
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;//cin>>t;
    t=1;
    vector<int> ans;
    while(t--){
        vector<int> in;
        int n;cin>>n;
        for(int i=0; i<n; i++){
            int tmp;cin>>tmp;
            in.push_back(tmp);
        }
        sort(in.begin(),in.end());
        reverse(in.begin(),in.end());
        int ptr=in.size()-1;
        int taxi=0;
        for(int i=0; i<=ptr;i++){
            if(in[i]==4){
                taxi++;
            }else if(in[i]+in[ptr]==4){
                taxi++;
                ptr--;
            }else if(in[i]+in[i+1]==4){
                taxi++;
                i++;
            }else{
                //32,12
                int o=0;
                for(int tr=i;tr<=ptr;tr++){
                    o+=in[tr];
                    if(in[tr]==3){
                        taxi++;
                        i++;
                    }
                }
                if(in[i]==2 || in[i]==1){
                    int tw=0,onee=0;
                    for(int rt=i;rt<=ptr;rt++){
                        if(in[rt]==2){
                            tw+=in[rt];
                        }
                        if(in[rt]==1){
                            onee+=in[rt];
                        }
                    }
                    int k=onee+tw;
                    taxi+= (k%4==0?(k/4):(k/4 + 1));
                    //taxi+= (tw%4==0?(tw/4):(tw/4 + 1));
                    //taxi+= (onee%4==0?(onee/4):(onee/4 + 1));
                    break;
                }
            }
        }
        ans.push_back(taxi);
    }
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<endl;
    }
    cout<<ans[ans.size()-1];
    return 0;
}
