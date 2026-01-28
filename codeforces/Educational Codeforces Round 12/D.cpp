#include <bits/stdc++.h>
using namespace std;
int n;
bitset<2000001> criba;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //par, par impar-> imposoble;
    // imp, imp par, -> possible only if imp=1 for all 1;
    //de lo contrario tam 2;
    criba[0]=criba[1]=1;
    for(int i=4;i<=2000000;i+=2)criba[i]=1;
    for(int i=3;i*i<=2000000;i+=2){
        if(criba[i])continue;
        for(int j=i*i;j<=2000000;j+=i)criba[j]=1;
    }
    cin >> n;
    int nums[n];
    int con1=0,num1=-1;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        if(nums[i]==1)con1++;
        else if(!criba[1+nums[i]])num1=nums[i];
    }
    if(con1+(num1!=-1)>=2){
        cout << con1+(num1!=-1) << '\n';
        while(con1--)cout << "1 ";
        if(num1!=-1)cout << num1;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(!criba[nums[i]+nums[j]]){
                cout << "2\n";
                cout << nums[i] << ' ' << nums[j];
                return 0;
            }
        }
    }
    cout << "1\n" << nums[0];
}