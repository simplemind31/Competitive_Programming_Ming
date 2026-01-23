#include <bits/stdc++.h>
using namespace std;
int n,m,q,a,b;
map<pair<int,int>,bool> ex;
bitset<200000> po;
int main(){
    cin >> n >> m >> q;
    while(q--){
        cin >> a;
        if(a==1){
            cin >> a >> b;
            ex[{--a,--b}]=true;
        }else if(a==2){
            cin >> a;
            po[--a]=true;
        }else{
            cin >> a >> b;
            if(po[--a] || ex[{a,--b}]){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
    }
}