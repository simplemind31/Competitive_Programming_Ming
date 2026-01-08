#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int C,G,T;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=0;i<st.size();i++){
        if(st[i]=='T'){
            T++;
        }else if(st[i]=='G'){
            G++;
        }else{
            C++;
        }
    }
    cout << T*T+G*G+C*C+7*min({C,T,G});
}