class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left<right)
            return rangeBitwiseAnd(left,right&(right-1));
        return right;
    }
};