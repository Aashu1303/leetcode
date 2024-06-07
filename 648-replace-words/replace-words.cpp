class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        unordered_map<string,int> mp;
        for(auto i : dictionary){
            mp[i]++;
        }
        string temp;
        for(int i = 0 ; i < sentence.size() ; i++){
            if(sentence[i] == ' '){
                string curr , to_push;
                for(int j = 0 ; j < temp.size() ; j++){
                    curr += temp[j];
                    if(mp[curr] > 0){
                        to_push = curr;
                        break;
                    } 
                }
                if(to_push.empty()){
                    ans += curr;
                }else{
                    ans += to_push;
                }
                ans.push_back(' ');
                temp = "";
            }
            else temp += sentence[i];
        }


        string curr , to_push;
        for(int j = 0 ; j < temp.size() ; j++){
            curr += temp[j];
            if(mp[curr] > 0) to_push = curr;
        }
        if(to_push.empty()){
            ans += curr;
        }else{
            ans += to_push;
        }
        
        return ans;
    }
};