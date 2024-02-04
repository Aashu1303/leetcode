class Solution {
public:
    string minWindow(string s, string t) {
        //base case
        if(t.size() > s.size()) {return "";}
        
        unordered_map<char,int> temp, mp;
        for(auto i : t){
            temp[i]++;
        }

        string ans = "", curr = "";
        int size = INT_MAX , i = 0 , j = i , total = 0;
        
        while(j < s.size()){
            mp[s[j]]++;
            curr += s[j];
            if(mp[s[j]] == temp[s[j]]){
                total+=mp[s[j]];
                //cout << "mai chal rha hu bc total wala" << total << endl;
            }
            while((mp[s[i]] > temp[s[i]]) && i < j){
                curr.erase(curr.begin());
                mp[s[i]]--;
                i++;
                cout << "mai chal rha hu bc delete wala" << endl;
            }
            if((size >= (j-i+1)) && (total >= t.size())){
                cout << "mai chal rha hu bc" << endl;
                ans = curr;
                size = (j-i+1);
            }
            j++;
        }
        return ans;
    }
};