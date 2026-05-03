#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    // cada need recibe al menos un have
    if(m<n){
        cout << "NO";
        return 0;
    }
    vector<int> need(n),have(m),nueneed,nuehav;
    for(int i=0;i<n;i++)cin >> need[i];
    for(int j=0;j<m;j++)cin >> have[j];
    sort(ALL(need));
    sort(ALL(have));
    int j=0,i=0;
    while(i<n && j<m){
        if(have[j]<need[i])nuehav.push_back(have[j++]);
        else if(have[j]>need[i])nueneed.push_back(need[i++]);
        else{
            i++;
            j++;
        }
    }
    while(i<n)nueneed.push_back(need[i++]);
    while(j<m)nuehav.push_back(have[j++]);
    need=nueneed;
    have=nuehav;
    n=need.size();
    m=have.size();
    if(!n){
        cout << "YES";
        return 0;
    }else if(m<2*n){
        cout << "NO";
        return 0;
    }
    pair<int,int> dp[1<<m];
    // maximum prefix que puedo completar si tengo el subset, sobra 
    fill(dp,dp+(1<<m),make_pair(-1,-1));
    dp[0]={0,0};
    for(int mask=1;mask<(1<<m);mask++){
        for(int i=0;i<m;i++){
            if(!(mask&(1<<i)))continue;
            if(dp[mask^(1<<i)].first==-1)continue;
            int now=have[i]+dp[mask^(1<<i)].second;
            if(now<need[dp[mask^(1<<i)].first]){
                if(dp[mask^(1<<i)].first>dp[mask].first)dp[mask]={dp[mask^(1<<i)].first,now};
            }else if(now==need[dp[mask^(1<<i)].first]){
                if(dp[mask^(1<<i)].first+1>dp[mask].first){
                    dp[mask]={dp[mask^(1<<i)].first+1,0};
                }
            }
        }
        if(dp[mask].first==n){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
// hay entre 0 y m-n salarios que pueden ser distintos a los de m para que tenga un matching
    // entonces hay n-(m-n),...,n que deben ser iguales a los que están en note
    // 2*n-m,...,n deben ser iguales a los que estan en note
    // pero ya elimine los que son iguales
    // entonces cada need esta conformado por lo menos 2 have
    // -> 2*n<=m
    // como m<=20 -> n<=10
    // brute force?
    // como cada need recibe al menos 2have
    // entonces habra a lo mucho m-2*n que tienen 3 have
    // entonces n-(m-2n)=3n-m tienen exactamente 2 