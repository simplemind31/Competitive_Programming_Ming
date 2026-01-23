#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool logi;
int n,con;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> st;
        logi=(st=="login")?true:(st=="logout")?false:logi;
        con+=(st=="private"&&!logi);
    }
    cout << con;
}