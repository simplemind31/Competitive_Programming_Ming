#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    vector<int> cubes(n);
    for(int i=0;i<n;i++){
        scanf("%d",&cubes[i]);
    }
    vector<int> nums;
    nums.push_back(cubes[0]);
    for(int i=1;i<n;i++){
        auto x=upper_bound(nums.begin(),nums.end(),cubes[i]);
        if(x==nums.end()){
            nums.push_back(cubes[i]);
        }else{
            *x=cubes[i];
        }
    }
    printf("%d",nums.size());
}