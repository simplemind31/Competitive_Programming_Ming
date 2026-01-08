#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
int n;
ll fact;
class Solution {
public:
    int countPermutations(vector<int>& complexity){
        n=complexity.size();
        for(int i=fact=1;i<n;i++){
            if(complexity[0]>=complexity[i])return 0;
            fact=(fact*i)%MOD;
        }
        return fact;
    }
};