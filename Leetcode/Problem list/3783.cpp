#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mirrorDistance(int n) {
        string s=to_string(n);
        reverse(s.begin(),s.end());
        return abs(n-stoi(s));
    }
};