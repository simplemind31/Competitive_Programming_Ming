#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
string st;
bitset<10> prime;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    prime[2]=prime[3]=prime[5]=prime[7]=true;
    cin >> t;
    while(t--){
        cin >> n >> st;
        bool xd=false;
        for(int i=0;i<n && !xd;i++){
            if(!prime[st[i]-'0']){
                cout << "1\n" << st[i]-'0' << '\n';
                xd=true;
            }
        }
        for(int i=0;i<n && !xd;i++){
            for(int j=i+1;j<n && !xd;j++){
                int num=10*(st[i]-'0')+st[j]-'0';
                for(int k=2;k*k<=num && !xd;k++){
                    if(num%k==0){
                        cout << "2\n" << num << '\n';
                        xd=true;
                    }
                }
            }
        }
    }
}