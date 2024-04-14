class Solution {
    unordered_map<int,int> mp;
    void sieveOfEratosthenes(int n) {
        vector<bool> prime(n + 1, true); // Create a boolean vector to mark numbers as prime or not
        prime[0] = prime[1] = false; // 0 and 1 are not prime

        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                mp[i]++;
            }
        }
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int first = -1 , last = -1;
        sieveOfEratosthenes(101);
        for(int i = 0 ; i < nums.size() ; i++){
            if(mp[nums[i]]){
                if(first == -1){
                    first = i;
                    last = i;
                }else{
                    last = i;
                }
            }
        }

        return last-first;
    }
};