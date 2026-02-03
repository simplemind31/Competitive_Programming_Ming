#include <bits/stdc++.h>
using namespace std;
char c;
int maxi,can=1,last=-1;
string st;
stack<pair<int,bool>> pila;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=0,n=st.size();i<n;i++){
        if(st[i]=='('){
            pila.push({i,true});
        }else{
            if(!pila.empty() && pila.top().second==true){
                pila.pop();
                if(pila.empty())last=-1;
                else last=pila.top().first;
                if(i-last>maxi){
                    maxi=i-last;
                    can=1;
                }else if(i-last==maxi){
                    can++;
                }
            }else{
                pila.push({i,false});
            }
        }
    }
    cout << maxi << ' ' << can;
}