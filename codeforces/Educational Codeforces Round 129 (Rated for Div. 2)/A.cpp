#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,m,x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int maxia=0,maxib=0;
        for(int i=0;i<n;i++){
            cin >> x;
            maxia=max(maxia,x);
        }
        cin >> m;
        for(int i=0;i<m;i++){
            cin >> x;
            maxib=max(maxib,x);
        }
        if(maxia>maxib)cout << "Alice\nAlice\n";
        else if(maxib>maxia)cout << "Bob\nBob\n";
        else cout << "Alice\nBob\n";
    }
}