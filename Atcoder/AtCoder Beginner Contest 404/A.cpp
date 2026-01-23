#include <bits/stdc++.h>
using namespace std;
int c,a;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(char c:st)a|=1<<(c-'a');
    for(int i=0;i<26;i++){
        if(!(a&(1<<i))){
            cout << char(i+'a');
            return 0;
        }
    }
}