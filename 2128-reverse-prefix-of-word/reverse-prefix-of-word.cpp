class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans;
        bool f = 1;
        int i = 0;
        while(i < word.length()){
            ans += word[i];
            if(word[i] == ch){
                f = 0 ; 
                break;
            } 
            i++;
        }
        i++;
        if(!f){
            reverse(ans.begin() , ans.end());
            for(i ; i < word.length() ; i++){
                ans += word[i];
            }
        }
        return ans;
    }
};