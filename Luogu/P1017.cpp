#include <bits/stdc++.h>
using namespace std;
int n,r;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> r;
    cout << n << "=";
    vector<int> remainder;
    while(!(n>=0 && n<abs(r))){
        int now=n%r;
        if(now<0){
            now+=abs(r);
        }
        remainder.push_back(now);
        n=(n-now)/r;
    }
    remainder.push_back(n);
    reverse(remainder.begin(),remainder.end());
    for(int i=0;i<remainder.size();i++){
        if(remainder[i]<10){
            cout << remainder[i];
        }else{
            char res=remainder[i]+'A'-10;
            cout << res;
        }
    }
    cout << "(base" << r << ")";
}