class Solution {
    void swap(int &a , int &b){
        int temp = a;
        a = b;
        b = temp;
        return;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        for(int i = n-2 ; i >= 0 ; --i){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        if(index == -1){
            sort(nums.begin() , nums.end());
            return;
        }

        for(int i = n-1 ; i >= index ; i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        sort(nums.begin()+index+1 , nums.end());
    }
};