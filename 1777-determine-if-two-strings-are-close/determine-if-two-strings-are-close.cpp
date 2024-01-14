class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(26,0) , v2(26,0);
        if(word1.length() != word2.length()) {
            return false;
        }
        for(auto i : word1) v1[i-'a']++;
        for(auto i : word2){
            if(v1[i-'a'] == 0) return false;
            v2[i-'a']++;
        } 
        sort(v1.begin() , v1.end());
        sort(v2.begin() , v2.end());
        for(int i = 0 ; i < 26 ; i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }

        return true;
    }
};