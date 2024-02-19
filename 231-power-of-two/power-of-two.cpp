class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int x = n-1;
        if((n & x) == 0) return true;
        return false;
    }
};