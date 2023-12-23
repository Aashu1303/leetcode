class Solution {
    long long countArray(vector<int> a, vector<int> b){
        int n = a.size();
        int m = b.size();

        long long count = 0;
        int i = 0 , j = 0;

        while(i < n && j < m){
            if(a[i] < b[j]){
                count += (m-j);
                i++;
            }else{
                j++;
            }
        }

        return count;
    }
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        long long count = 1; // considering empty subarray
        int n = nums.size();
        if(n == 1) return 1;
        int i = 0 , j = n-1;
        vector<int> prefix , suffix;
        while(i < n-1 && nums[i] < nums[i+1]){
            prefix.push_back(nums[i++]);
        }
        prefix.push_back(nums[i]);
        while(j-1>=0 && nums[j]>nums[j-1]){
            suffix.push_back(nums[j--]);
        }
        suffix.push_back(nums[j]);
        reverse(suffix.begin() , suffix.end());
        
        if(j < i){
            count = (1ll*n*(n+1)*1LL)/2;
            return count;
        }

        int l = prefix.size() , m = suffix.size(); 
        count += (l + m);
        count += countArray(prefix , suffix);

        return count;
    }   
};