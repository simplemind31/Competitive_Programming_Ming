#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares){
        int con=0,n=squares.size();
        double l=0,r=1e9;
        while(con++<47){
            double mid=(l+r)/2,aiz=0,ade=0;
            for(int i=0;i<n;i++){
                if((double)squares[i][1]>=mid)ade+=(double)squares[i][2]*squares[i][2];
                else if((double)squares[i][1]+squares[i][2]<=mid)aiz+=(double)squares[i][2]*squares[i][2];
                else{
                    aiz+=(mid-squares[i][1])*(double)squares[i][2];
                    ade+=(squares[i][1]+squares[i][2]-mid)*squares[i][2];
                }
            }
            if(aiz>=ade)r=mid;
            else l=mid;
        }
        return l;
    }
};