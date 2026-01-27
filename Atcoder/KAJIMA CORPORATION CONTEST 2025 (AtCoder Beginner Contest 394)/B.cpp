#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int n,mini=1e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n];
    int l=0;
    map<int,bool> con;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        while(con[nums[i]]){
            mini=min(mini,i-l+1);
            con[nums[l++]]=false;
        }
        con[nums[i]]=true;
    }
    if(mini==1e9)cout <<-1;
    else cout << mini;
}