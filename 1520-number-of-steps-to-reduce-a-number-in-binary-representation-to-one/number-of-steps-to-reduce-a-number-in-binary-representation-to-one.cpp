class Solution {
public:
    int numSteps(string s) {
        reverse(s.begin() , s.end());
        int count = 0;
        while(s.size() > 1){
            int x = s.size();
            count++;
            if(s[0] == '1'){
                s[0] = '0';
                bool f = true;
                for(int i = 1 ; i < x ; i++){
                    if(s[i] == '0'){
                        s[i] = '1';
                        f = false;
                        break;
                    }else{
                        s[i] = '0';
                    }
                }
                if(f) s.push_back('1');
            }else{
                // string temp;
                for(int i = 1 ; i < x ; i++){
                    s[i-1] = s[i];
                }
                s.pop_back();
            }
            //cout << s << " " << count << endl;
        }
        return count;
    }
};