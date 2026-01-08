#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    short smallestNumber(short n){
        return (1<<(short)log2(n)+1)-1;
    }
};