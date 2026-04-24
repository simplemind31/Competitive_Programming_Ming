#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int furthestDistanceFromOrigin(string moves){
        int n=moves.size(),pos=0,con=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='L')pos--;
            else if(moves[i]=='R')pos++;
            else con++;
        }
        return abs(pos)+con;
    }
};