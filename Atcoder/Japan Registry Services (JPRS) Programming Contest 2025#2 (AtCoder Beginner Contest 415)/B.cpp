#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int iz=-1;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=0,n=st.size();i<n;i++){
        if(st[i]=='#'){
            if(iz==-1)iz=i;
            else{
                cout << iz+1 << ',' << i+1 << '\n';
                iz=-1;
            }
        }
    }
}