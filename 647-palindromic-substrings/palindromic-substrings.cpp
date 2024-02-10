class Solution {
    int isPalindrome(int i , int j , string &s){
        int count = 0;
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            count++;
            j++;
            i--;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            int oddLength = isPalindrome(i , i , s);
            int evenLength = isPalindrome(i , i+1 , s);
            count += (oddLength + evenLength);
        }
        // for(auto i : dp) cout << i << " ";
        return count;
    }
};