#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        if(target==words[startIndex])return 0;
        int mini=1e9;
        for(int i=(startIndex+1)%n;i!=startIndex;i=(i+1)%n){
            if(words[i]==target){
                mini=min(mini,(i+n-startIndex)%n);
                break;
            }
        }
        for(int i=(startIndex-1+n)%n;i!=startIndex;i=(i-1+n)%n){
            if(words[i]==target){
                mini=min(mini,(n+startIndex-i)%n);
                break;
            }
        }
        if(mini==1e9)mini=-1;
        return mini;
    }
};