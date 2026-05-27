#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
typedef long long ll;
int a,n;
set<int> nums;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    if(n<2){
        cout << "No hay suficiente información\n";
        return 0;
    }
    while(n--){
        cin >> a;
        nums.insert(a);
    }
    if(nums.size()==1)cout << "No hay un segundo número mayor\n";
    else cout << *(----nums.end()) << '\n';
}