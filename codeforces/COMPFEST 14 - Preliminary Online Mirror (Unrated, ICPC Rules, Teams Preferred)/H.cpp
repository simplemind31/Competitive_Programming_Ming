#include <bits/stdc++.h>
using namespace std;
int n,a,con[3];
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> nums(n);
    vector<bool> res(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
        con[nums[i]%=3]++;
    }
    /*
    (a+b)*(a+b)+a*b==z mod3
    a*a+3ab+b*b==z mod3
    a*a+b*b==z mod3;
    si z=0
    => a=0 y b=0
    solo si todo 0 son del mismo
    si z=1
    => (a=0 y b!=0) || (a!=0 y b==0)
    => 0 debe unir si o si con otro
    => solo si con[0]=0
    si z=2
    a!=0 y b!=0;
    => 1 no puede unir con 1 ni 2
    2 tampoco ni con 1 ni con 2
    => todos 1 y 2 del mismo bando
    */
    if(con[0]<=n/2){
        int cont=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                res[i]=1;
                cont++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0 && cont<n/2){
                res[i]=1;
                cont++;
            }
        }
        cout << "0\n";
        for(int i=0;i<n;i++){
            cout << res[i];
        }
        return 0;
    }
    if(con[0]==0){
        cout << "1\n";
        for(int i=0;i<n/2;i++){
            cout << 1;
        }
        for(int i=n/2;i<n;i++){
            cout << 0;
        }
        return 0;
    }
    if(con[1]+con[2]<=n/2){
        int cont=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                res[i]=1;
                cont++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0 && cont<n/2){
                res[i]=1;
                cont++;
            }
        }
        cout << "2\n";
        for(int i=0;i<n;i++){
            cout << res[i];
        }
        return 0;
    }
    cout << -1;
}
// 1 1 0 2 