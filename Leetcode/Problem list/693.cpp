class Solution {
public:
    bool hasAlternatingBits(int n){
        int last=n&(-n);
        if(n&1){
            // pos par 0,2,4
            while(n){
                if(!(n&1))return false;
                n>>=1;
                if(n&1)return false;
                n>>=1;
            }
        }else{
            while(n){
                if(n&1)return false;
                n>>=1;
                if(!(n&1))return false;
                n>>=1;
            }
        }
        return true;
    }
};