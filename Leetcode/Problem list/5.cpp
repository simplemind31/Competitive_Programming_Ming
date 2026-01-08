#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll n,ri,rj;
string res;
class Solution {
public:
    string longestPalindrome(string s){
        mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
        res="";
        n=s.size();
        vector<ll> hashval(300);
        ll constante=uniform_int_distribution<ll> (1,MOD-1)(rng);
        for(int i=0;i<300;i++){
            hashval[i]=uniform_int_distribution<ll> (1,MOD-1)(rng);

        }
        ri=rj=0;
        ll ori[n][n];
        for(int i=0;i<n;i++){
            ll num=0;
            for(int j=i;j<n;j++){
                num*=constante;
                num+=hashval[s[j]];
                num%=MOD;
                ori[i][j]=num;
                //cout << num << ' ';
            }
            //cout << endl;
        }
        for(int i=n-1;i>=0;i--){
            ll num=0;
            for(int j=i;j>=0;j--){
                num*=constante;
                num+=hashval[s[j]];
                num%=MOD;
                if(num==ori[j][i]){
                    if(rj-ri+1<i-j+1){
                        ri=j;
                        rj=i;
                    }
                }
                //cout << num << ' ';
            }
            //cout << endl;
        }
        for(int i=ri;i<=rj;i++){
            res.push_back(s[i]);
        }
        return res;
    }
};