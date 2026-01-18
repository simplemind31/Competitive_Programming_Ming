#include <bits/stdc++.h>
using namespace std;
int con;
string al;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("circlecross.in","r",stdin);
    freopen("circlecross.out","w",stdout);
    cin >> al;
    for(int i=0;i<52;i++){
        vector<bool> x(26); 
        for(int j=0;j<52;j++){
            if(al[i]!=al[j])continue;
            for(int k=i+1;k<j;k++)x[al[k]-'A']=!x[al[k]-'A'];
        }
        for(int j=0;j<26;j++)if(x[j])con++;
    }
    cout << con/2;
}