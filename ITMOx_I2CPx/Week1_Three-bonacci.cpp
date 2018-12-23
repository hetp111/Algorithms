//#include <bits/stdc++.h> by het-
#include <iostream>
#include <fstream>
using namespace std;
long long arr[1000000];

long long T(long long A0, long long A1, long long A2, long long i){
    if(i==0){
        return A0;
    }else if(i==1){
        return A1;
    }else if(i==2){
        return A2;
    }
    if(arr[i]!=-999)return arr[i];
    arr[i] = T(A0,A1,A2,i-1)+T(A0,A1,A2,i-2)-T(A0,A1,A2,i-3);
    return arr[i];
}

int main()
{
    ifstream inf("input.txt");
    ofstream ouf("output.txt");
    for(int i=0;i<1000000;i++){
        arr[i]=-999;
    }
    long long A0,A1,A2,n;
    inf>>A0>>A1>>A2>>n;
    long long ans = T(A0,A1,A2,n);
    ouf<<ans;
    return 0;
}
