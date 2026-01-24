#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,t,f,s,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> f;
        set<int> nums;
        con=0;
        for(int i=1;i<n-1;i++){
            cin >> s;
            nums.insert(s);
        }
        cin >> s;
        con=2;
        while(2*f<s && !nums.empty()){
            auto nue=nums.upper_bound(2*f);
            if(nue==nums.begin())break;
            nue--;
            if(*nue<=f)break;
            f=*nue;
            con++;
        }
        if(2*f<s)cout << "-1\n";
        else cout << con << '\n';
    }
}