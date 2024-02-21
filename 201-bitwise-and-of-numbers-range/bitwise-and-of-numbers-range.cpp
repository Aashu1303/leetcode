class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(right == left) return (right & left);
        unsigned int x , y;
        for(int i = 31 ; i >= 0 ; i--){
            x = 1 << i;
           // cout << x << endl;
            if(x <= right){
                y = x;
                break;                
            }
        }
        if(x <= left){
            int ans = left;
            for(unsigned int i = left + 1 ; i <= right ; i++){
                ans &= i;
            }
            return ans;
        }
        int ans = 0;
        for(unsigned int i = y+1 ; i <= right ; i++){
            ans &= i;
        }
        return ans;
    }
};