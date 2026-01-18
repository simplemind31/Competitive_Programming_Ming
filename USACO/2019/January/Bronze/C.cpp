#include <bits/stdc++.h>
using namespace std;
int n,a,maxi;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);
    cin >> n;
    vector<map<string,bool>> anima(n);
    for(int i=0;i<n;i++){
        cin >> s >> a;
        while(a--){
            cin >> s;
            anima[i][s]=true;
        }
        for(int j=0;j<i;j++){
            int con=0;
            for(auto u:anima[j]){
                if(u.second==false)continue;
                if(anima[i][u.first])con++;
            }
            //if(max(anima[i].size(),anima[j].size())>con)con++;
            maxi=max(maxi,con);
            //cout << maxi << ' ';
        }
        //cout << '\n';
    }
    cout << maxi+1;
}