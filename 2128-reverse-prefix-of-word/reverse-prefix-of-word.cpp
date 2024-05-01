class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = word.find(ch);
        int x = (j - 1)/2;
        for(int i = 0 ; i <= x ; i++){
            swap(word[i] , word[j-i]);
        }
        return word;
    }
};