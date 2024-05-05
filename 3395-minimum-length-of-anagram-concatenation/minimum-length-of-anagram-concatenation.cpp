class Solution {
    
public:
    int minAnagramLength(string s) {
        vector<int> freq(26 , 0) , temp(26,0);
        int n = s.size() , ans = INT_MAX;
        for(auto i : s){
            freq[i-'a']++;
        }

        for(int i = 0 ; i < s.size() ; i++){
            temp[s[i] - 'a']++;
            if(n % (i+1) == 0){
                int curr = n/(i+1);
                bool flag = true;
                for(int j = 0 ; j < 26 ; j++){
                    if((temp[j]*curr) != freq[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag) ans = min(ans , i+1); 
            }
        }

        return ans;
    }
};