#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
#define MOD 1000000007
int n,t,last,con;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    getline(cin,s);
    while(t--){
        last=-1;
        con=0;
        getline(cin,s);
        n=s.size();
        for(int i=0;i<n;i++){
            if(0<=s[i]-'0' && s[i]-'0'<=9){
                last=i;
                break;
            }
        }
        if(last==-1){
            cout << "Valid\n";
            continue;
        }
        bool xd=true;
        for(int i=last+1;i<n;i++){
            if(s[i]=='?'){
                con++;
            }else if(0<=s[i]-'0' && s[i]-'0'<=9){
                if(con!=s[i]-'0'+s[last]-'0'){
                    xd=false;
                    break;
                }
                last=i;
                con=0;
            }
        }
        if(xd){
            cout << "Valid\n";
        }else{
            cout << "Invalid\n";
        }
    }
}