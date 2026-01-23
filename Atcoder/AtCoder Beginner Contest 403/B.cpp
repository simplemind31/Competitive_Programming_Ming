#include <bits/stdc++.h>
using namespace std;
string s,t;
int main(){
    cin >> s >> t;
    for(int i=0;i<=s.size()-t.size();i++){
        bool xd=true;
        for(int j=0;j<t.size();j++){
            if(!(s[i+j]=='?'||s[i+j]==t[j]))xd=false;
        }
        if(xd){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}