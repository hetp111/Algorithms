//#include <bits/stdc++.h>het-
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    ifstream inf("input.txt");
    ofstream ouf("output.txt");
    vector<long double> A,B,C;
    long double maxx=-1;
    for(int i=0;i<3;i++){
        long double tmp;
        inf>>tmp;
        A.push_back(tmp);
    }
    for(int i=0;i<3;i++){
        long double tmp;
        inf>>tmp;
        B.push_back(tmp);
    }
    for(int i=0;i<3;i++){
        long double tmp;
        inf>>tmp;
        C.push_back(tmp);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                long double t=sqrt(A[i]*A[i]+B[j]*B[j]+C[k]*C[k]);
                if(maxx<=t && i!=j && j!=k && k!=i){
                    maxx=t;
                }
            }
        }
    }
    ouf<<setprecision(50)<<maxx;
    return 0;
}
