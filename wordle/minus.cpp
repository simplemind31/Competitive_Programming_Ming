#include <bits/stdc++.h>
using namespace std;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("wordsnew.txt");
    ofstream fout("target.txt");
    while(fin >> st){
        for(auto u:st)fout << char(u-'A'+'a');
        fout << '\n';
    }
}