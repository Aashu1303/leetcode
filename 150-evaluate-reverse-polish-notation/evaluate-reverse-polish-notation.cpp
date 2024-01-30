class Solution {
    int perform(int a , int b , string s){
        if(s == "+") return a + b;
        else if(s == "-") return a - b;
        else if(s == "*") return a*b;
        else{
            if(b != 0){
                return a/b;
            }
            return 0;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> s;
        vector<int> t;
        for(int i = 0 ; i < n ; i++){
            if(!(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")){
                int x = stoi(tokens[i]);
                t.push_back(x);
            }else{
                int size = t.size();
                int one = t[size - 2] , two = t[size - 1];
                t.pop_back();
                t.pop_back();
                t.push_back(perform(one , two , tokens[i]));
            }
        }

        return t[0];
    }
};