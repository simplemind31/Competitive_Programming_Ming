#include <bits/stdc++.h>
using namespace std;
string st;
int con,maxi,pos;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=0;i<st.size();i++){
        if(st[i]=='+')con++;
        else con--;
        if(con>maxi){
            con=maxi;
            pos=i;
        }
    }
    cout << pos+1;
}