#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int con1,con2;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=st.size()-1;i>=0;i--){
        con2+=(st[i]-'0'-con1+10)%10+1;
        con1=(st[i]-'0')%10;
    }
    cout << con2;
}