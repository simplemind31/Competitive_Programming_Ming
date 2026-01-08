#include <bits/stdc++.h>
using namespace std;
string st;
int sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=0;i<st.size();i++){
        if(st[i]=='(')sum++;
        else sum--;
        if(sum<0){
            cout << "NO";
            return 0;
        }
    }
    if(sum){
        cout << "NO";
        return 0;
    }
    cout << "YES";
}