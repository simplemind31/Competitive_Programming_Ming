#include <bits/stdc++.h>
using namespace std;
int n,t,res;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        res=0;
        cin >> n >> st;
        vector<bool> con(26);
        for(int i=0;i<n;i++){
            if(!con[st[i]-'A'])res++;
            con[st[i]-'A']=1;
        }
        cout << n+res << '\n';
    }
}