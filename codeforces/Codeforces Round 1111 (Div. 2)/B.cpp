#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int t=1,n,k,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k >> m;
        // los primeros k con multiplo de m
        // los primeros m si o si un multiplo de m
        if(m<=k-1){
            cout << "NO\n";
            continue;
        }
        // todo 1 
        vector<int> nums(n);
        cout << "YES\n";
        for(int i=0;i<k-1;i++)cout << (nums[i]=1) << ' ';
        cout << (nums[k-1]=m-(k-1)) << ' ';
        for(int i=k;i<n;i++)cout << (nums[i]=nums[i-k]) << ' ';
        cout << '\n';
    }
}