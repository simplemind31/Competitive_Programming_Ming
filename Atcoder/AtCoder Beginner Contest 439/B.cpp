#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int n,con=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(con<10000000){
        int b=0;
        while(n>0){
            b+=(n%10)*(n%10);
            n/=10;
        }
        n=b;
        con++;
    }
    if(n==1){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}