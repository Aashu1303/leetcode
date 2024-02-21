class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // if(right == left) return (right & left);
        // unsigned int x , y;
        // for(int i = 31 ; i >= 0 ; i--){
        //     x = 1 << i;
        //     if(x <= right){
        //         y = x;
        //         break;
        //     }
        // }
        // //cout << x << endl;
        // int ans = (x <= left) ? left : 0;
        // unsigned int i = (x <= left) ? left+1 : y+1;
        // for(i ; i <= right ; i++){
        //     ans &= i;
        // }
        // return ans;
        while(right>left){
            right&=(right-1);
        }
        return right;
    }
};