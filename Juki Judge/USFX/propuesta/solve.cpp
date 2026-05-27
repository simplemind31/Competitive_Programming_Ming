#include <bits/stdc++.h>
using namespace std;
int n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<=10;i++){
        string fil="test"+to_string(i)+".in";
        string ou="test"+to_string(i)+".out";
        ifstream fin(fil);
        ofstream fout(ou);
        fin >> n;
        vector<bool> con(n);
        for(int i=0;i<n;i++){
            fin >> a;
            con[a-1]=1;
        }
        for(int i=0;i<n;i++){
            if(!con[i])fout << i+1 << ' ';
        }
    }
}