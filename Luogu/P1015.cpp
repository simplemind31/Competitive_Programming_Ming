#include <bits/stdc++.h>
using namespace std;
int m;
string n,rev;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> m >> n;
    for(int i=0;i<n.size();i++){
        if(n[i]>='A'){
            n[i]=n[i]+'0'+10-'A';
        }
    }
    for(int i=0;i<31;i++){
        rev=n;
        reverse(rev.begin(),rev.end());
        if(n==rev){
            cout << "STEP=" << i;
            return 0;
        }
        int sobra=0;
        for(int j=0;j<n.size();j++){
            int con=n[j]-'0'+rev[j]-'0'+sobra;
            n[j]=con%m+'0';
            sobra=con/m;
        }
        if(sobra!=0){
            n.push_back(sobra+'0');
        }
        reverse(n.begin(),n.end());
    }
    cout << "Impossible!";
}