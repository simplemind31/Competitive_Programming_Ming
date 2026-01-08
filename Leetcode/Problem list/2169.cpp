#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countOperations(int num1,int num2){return (num2)?countOperations(num2,num1%num2)+num1/num2:0;}
};