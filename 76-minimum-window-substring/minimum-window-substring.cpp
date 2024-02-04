class Solution {
public:
    string minWindow(string s, string t) {
        //base case
        if(t.size() > s.size()) {return "";}
        
        vector<int> temp(128,0), mp(128,0);
        for(auto i : t){
            temp[i -'A']++;
        }

        string ans = "", curr = "";
        int size = INT_MAX , i = 0 , j = i , total = 0;
        
        while(j < s.size()){
            mp[s[j]-'A']++;
            curr += s[j];
            if(mp[s[j]-'A'] == temp[s[j]-'A']){
                total += mp[s[j]-'A'];
            }
            while((mp[s[i]-'A'] > temp[s[i]-'A']) && (i < j)){
                curr.erase(0,1);
                mp[s[i]-'A']--;
                i++;
            }
            if((size >= (j-i+1)) && (total == t.size())){
                ans = curr;
                size = (j-i+1);
            }
            j++;
        }
        return ans;
    }
};