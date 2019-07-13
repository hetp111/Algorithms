//by hetp111
//https://codeforces.com/problemset/problem/122/A

//string to int to string ;)

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t=1;//cin>>t;
    vector<string> ans;
    while(t--){
        int n;cin>>n;
        vector<int> luckyNum;
        for(int i=1;i<=1000;i++){
            string s=to_string(i);//to string
            int flg=1;
            for(int h=0;h<s.size();h++){
                if(s[h]!='4' && s[h]!='7'){
                    flg=0;
                    break;
                }
            }
            if(flg==1){
                luckyNum.push_back(stod(s));//string to decimal
            }
        }
        //cout<<luckyNum.size();
        //for(int asddff:luckyNum){
        //    cout<<asddff<<endl;
        //}
        for(int i=0; i<luckyNum.size();i++){
            if(n%luckyNum[i]==0){
                cout<<"YES";
                exit(0);
            }
        }
        cout<<"NO";

    }

    for(string ghj:ans){
        cout<<ghj<<endl;
    }
    return 0;
}
