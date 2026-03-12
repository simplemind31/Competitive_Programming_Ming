class Solution {
public:
    int findComplement(int num){
        if(num==0)return 1;
        return num^(((unsigned int)1<<(32-__builtin_clz(num)))-1);
    }
};