class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int , int> mp;
        for(auto i : arr1){
            mp[i]++;
        }

        for(int i = 0 ; i < arr2.size() ; i++){
            while(mp[arr2[i]]--){
                ans.push_back(arr2[i]);
            }
        }

        for(int i = 0  ; i < mp.size() ; i++){
            if(mp[i] != -1){
                while(mp[i]--){
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};