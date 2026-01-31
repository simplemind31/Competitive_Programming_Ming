#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters,char target){return (upper_bound(letters.begin(),letters.end(),target)!=letters.end())?*upper_bound(letters.begin(),letters.end(),target):letters[0];}
};