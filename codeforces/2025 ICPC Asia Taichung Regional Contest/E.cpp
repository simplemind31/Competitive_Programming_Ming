#include <bits/stdc++.h>
using namespace std;
int t,n,j,k,con;
string st[3];
vector<string> per[3];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    st[0]="12";
    st[1]="123";
    st[2]="1234";
    for(int i=0;i<3;i++)do{per[i].push_back(st[i]);}while(next_permutation(st[i].begin(),st[i].end()));
    cin >> t;
    while(t--){
        con=0;
        cin >> n >> j >> k;
        j--;k--;
        string s1,s2;
        if(n==12){
            s1=per[0][j];
            s2=per[0][k];
        }else if(n==123){
            s1=per[1][j];
            s2=per[1][k];
        }else{
            s1=per[2][j];
            s2=per[2][k];
        }
        n=s1.size();
        for(int i=0;i<n;i++)if(s1[i]==s2[i])con++;
        cout << con << "A" << n-con << "B\n";
    }
}