class Solution {
    bool isPalindrome(string s){
        int i = 0 , j = s.size()-1;
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(auto i : words){
            if(isPalindrome(i)) return i;
        }

        return "";
    }
};