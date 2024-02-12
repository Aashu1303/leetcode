class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer's Voting algorithm
        int count = 0 , ans = 1;
        for(auto i : nums){
            if(count == 0) ans = i;
            
            if(ans == i){
                count++;
            }else{
                count --;
            }
        }

        return ans;

    }
};