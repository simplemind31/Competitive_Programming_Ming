#include <bits/stdc++.h>
using namespace std;
bool xd,existe[1000002];
int n,nums[1000002];
void solve(int mini,int posi){
    if(posi==n){
        xd=true;
        return;
    }
    for(int i=mini;i<=n;i++){
        if(existe[i] || abs(i-nums[posi-1])==1)continue;
        existe[i]=true;
        nums[posi]=i;
        int nextun=mini;
        while(existe[nextun])nextun++;
        solve(nextun,posi+1);
        if(xd)return;
        existe[i]=false;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int pos=0;
    if(n==1){
        cout << 1;
        return 0;
    }else if(n<=3){
        cout << "NO SOLUTION";
        return 0;
    }else if(n==4){
        cout << "2 4 1 3";
        return 0;
    }
    int now=1;
    nums[pos++]=1;
    existe[1]=true;
    while(nums[pos-1]<=n-20){
        while(existe[now])now++;
        if(abs(nums[pos-1]-now)<=1){
            existe[nums[pos-1]+2]=true;
            nums[pos]=nums[pos-1]+2;
            pos++;
        }else{
            existe[now]=true;
            nums[pos++]=now;
        }
    }
    while(existe[now])now++;
    solve(now,pos);
    for(int i=0;i<n;i++){
        cout << nums[i] << ' ';
    }
}