#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int n,t=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int nums[n];
        for(int i=0;i<n;i++){
            cin >> nums[i];
            nums[i]--;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=n-i-1){
                for(int j=i+1;j<n;j++){
                    if(nums[j]==n-i-1){
                        reverse(nums+i,nums+j+1);
                        break;
                    }
                }
                break;
            }
        }
        for(int i=0;i<n;i++){
            cout << nums[i]+1 << ' ';
        }
        cout << '\n';
    }
}