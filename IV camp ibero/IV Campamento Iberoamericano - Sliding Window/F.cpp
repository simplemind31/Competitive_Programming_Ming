#include <bits/stdc++.h>
using namespace std;
int n,q,tot[26],a,ini;
vector<pair<int,int>> inifin[26];
string st;
char c='0';
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> st;
    int dp[n][26];
    tot[st[0]-'a']++;
    for(int j=0;j<26;j++)dp[0][j]=-1;
    for(int i=1;i<n;i++){
        for(int j=0;j<26;j++)dp[i][j]=-1;
        tot[st[i]-'a']++;
        if(st[i]!=st[i-1]){
            inifin[st[i-1]-'a'].push_back({ini,i-1});
            ini=i;
        }
    }
    inifin[st.back()-'a'].push_back({ini,n-1});
    cin >> q;
    while(q--){
        cin >> a >> c;
        if(dp[a-1][c-'a']!=-1){
            cout << dp[a-1][c-'a'] << '\n';
            continue;
        }else if(a>=n-tot[c-'a']){
            cout << (dp[a-1][c-'a']=n) << '\n';
            continue;
        }else if(!tot[c-'a']){
            cout << (dp[a-1][c-'a']=a) << '\n';
            continue;
        }
        int l=0,r=0,cantiusado=0,can=0;
        while(r<inifin[c-'a'].size()){
            if(l==r){
                can=inifin[c-'a'][l].second-inifin[c-'a'][l].first+1;
                cantiusado=0;
                dp[a-1][c-'a']=max(dp[a-1][c-'a'],can+a-cantiusado);
                r++;
            }else if(cantiusado+inifin[c-'a'][r].first-inifin[c-'a'][r-1].second-1<=a){
                cantiusado+=inifin[c-'a'][r].first-inifin[c-'a'][r-1].second-1;
                can+=inifin[c-'a'][r].second-inifin[c-'a'][r].first+1;
                can+=inifin[c-'a'][r].first-inifin[c-'a'][r-1].second-1;
                dp[a-1][c-'a']=max(dp[a-1][c-'a'],can+a-cantiusado);
                r++;
            }else{
                //reducir
                can-=inifin[c-'a'][l].second-inifin[c-'a'][l].first+1;
                can-=inifin[c-'a'][l+1].first-inifin[c-'a'][l].second-1;
                cantiusado-=inifin[c-'a'][l+1].first-inifin[c-'a'][l].second-1;
                l++;
            }
            //cout << l << ' ' << r << ' ' << dp[a-1][c-'a'] << '\n';
        }
        cout << dp[a-1][c-'a'] << '\n';
    }
}