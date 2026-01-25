#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long double maxi;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=0,n=st.size();i<n;i++){
        if(st[i]!='t')continue;
        int con=0;
        for(int j=i;j<n;j++){
            if(st[j]=='t'){
                con++;
                if(j>i+1){
                    maxi=max(maxi,(long double)(con-2)/(j-i+1-2));
                }
            }
        }
    }
    cout << fixed << setprecision(12) << maxi;
}