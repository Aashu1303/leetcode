class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        map<double,pair<int,int>> mp;
        for(int i = 0 ; i < arr.size() ; i++){
            for(int j = i+1 ; j < arr.size() ; j++){
                double temp = (double)arr[i] / (double)arr[j];
                mp[temp] = {arr[i] , arr[j]};
            }
        }
        int count = 0;
        for(auto i : mp){
            count++;
            if(count == k) return {i.second.first , i.second.second};
        }
        return {-1,-1};
    }
};