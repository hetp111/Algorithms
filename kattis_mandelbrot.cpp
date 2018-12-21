//https://open.kattis.com/submissions/3594172 - mandelbrot - in or out
//het patel - hetp111
#include<bits/stdc++.h>
using namespace std;
class Complex{
public:
    float x,y;
    Complex(float,float);
    Complex operator+(Complex);
    Complex operator*(Complex);
    float mod();
};

Complex::Complex(float x, float y){
    this->x = x;
    this->y = y;
}
Complex Complex::operator*(Complex c){
    Complex cn(0,0);
    cn.x = (this->x)*(c.x) - (this->y)*(c.y);
    cn.y = (this->x)*c.y + (this->y)*c.x;
    return cn;
}

Complex Complex::operator+(Complex c){
    Complex cn(0,0);
    cn.x = this->x + c.x;
    cn.y = this->y + c.y;
    return cn;
}

float Complex::mod(){
    return sqrt((this->x)*(this->x)+(this->y)*(this->y));
}

main(){
    float x,y;int r;int ii=0;
    vector<string> ans;
    while(cin>>x){
        ii++;
        cin>>y;cin>>r;
        Complex c(x,y);
        Complex z(0,0);
        int flg=0;
        while(r--){
            z = z*z + c;
            if(z.mod()>2){
                flg=1;
                ans.push_back("Case "+to_string(ii)+": OUT");
                break;
            }
        }
        if(!flg){
            ans.push_back("Case "+to_string(ii)+": IN");
        }
    }

    for(string s:ans){
        cout<<s<<endl;
    }


}
