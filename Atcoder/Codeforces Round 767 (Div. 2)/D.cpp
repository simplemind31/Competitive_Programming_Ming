#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int t,n;
string st,x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        map<string,bool> con;
        bool xd=false;
        for(int i=0;i<n;i++){
            cin >> st;
            con[st]=true;
            string nue=st;
            reverse(ALL(nue));
            if(con[nue]){
                xd=true;
            }
            if(st.size()==3){
                string temp="";
                temp.push_back(st[2]);
                temp.push_back(st[1]);
                if(con[temp]){
                    xd=true;
                }
                temp="";
                temp.push_back(st[0]);
                temp.push_back(st[1]);
                if(con[temp]){
                    xd=true;
                }
            }
            con[st]=true;
        }
        if(xd)cout << "YES\n";
        else cout << "NO\n";
    }
}