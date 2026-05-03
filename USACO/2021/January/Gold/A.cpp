#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,can[20][20],now;
int correspond[26];
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    int n=st.size();
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        if(!correspond[st[i]-'a'])correspond[st[i]-'a']=++now;
        nums[i]=correspond[st[i]-'a']-1;
    }
    int can[now][now];
    memset(can,0,sizeof(can));
    for(int i=0;i+1<n;i++){
        can[nums[i]][nums[i+1]]++;
        /*for(int j=i+1;j<n;j++){
            can[nums[i]][nums[j]]++;
            if(nums[i]==nums[j])break;
        }*/
    }
    n=now;
    int dp[1<<n];
    // minimo si utilizo el subset y el ultimo era i
    fill(dp,dp+(1<<n),1e9);
    dp[0]=0;
    for(int mask=1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i)))continue;
            int temp=0;
            for(int j=0;j<n;j++)if(mask&(1<<j))temp+=can[i][j];
            dp[mask]=min(dp[mask],dp[mask^(1<<i)]+temp);
            // el i fue el ultimo del subset, para tener ciclos,dp[mask^1(<<i)]+cada que hay uno despues de i
            // no siempre, si k<j<i y hemos contado j,k no debemos contar i,k si estan en j,i,k
        }
    }
    cout << dp[(1<<n)-1]+1;
}