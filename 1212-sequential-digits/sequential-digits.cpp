class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        long long start = 12 , t = 12 ,add = 11;
        vector<int> temp;
        while(t <= high){
            if(t % 10 == 0){
                t = (start * 10) + ((start % 10)+1);
                add = (add*10)+1;
                start = t;
            }
            temp.push_back(t);
            t += add;
        }

        for(auto i : temp){
            if(i >= low && i <= high) ans.push_back(i);
        }
        return ans;
    }
};