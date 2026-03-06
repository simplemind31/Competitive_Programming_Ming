#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkOnesSegment(string s){
        while(!s.empty() && s.back()=='0')s.pop_back();
        while(!s.empty() && s.back()=='1')s.pop_back();
        while(!s.empty() && s.back()=='0')s.pop_back();
        return s.empty();
    }
};