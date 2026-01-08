#include <bits/stdc++.h>
using namespace std;
int i,j,c;
class Solution{
public:
    int countCollisions(string directions){
        i=c=0;
        j=directions.size()-1;
        for(;i<=j && directions[i]=='L';i++);
        for(;i<=j && directions[j]=='R';j--);
        for(int x=i;x<=j;x++)if(directions[x]=='S')c++;
        return j-i+1-c;
    }
};