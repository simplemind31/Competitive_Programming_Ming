#include <bits/stdc++.h>
using namespace std;
int a,b;
class Solution {
public:
    int totalMoney(int n){return(7*(a=n/7)*(a+7)+(2*a+1+(b=n%7))*b)/2;}
};