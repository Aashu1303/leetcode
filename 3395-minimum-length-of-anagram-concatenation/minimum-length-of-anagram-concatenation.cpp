class Solution {
    bool compare(string s1, string s2){
        //cout<<" compare "<<s1<<", "<<s2; 
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for(int i=0; i<s1.length(); i++){
            v1[int(s1[i]-97)]++;
            v2[int(s2[i]-97)]++;
        }
        if(v1==v2)return true;
        else return false;
    }
    public:
    int minAnagramLength(string s) {
        
        for(int k=1; k<=s.length()/2; k++){
            // cout<<endl;
            // cout<<k;
            if(s.length()%k!=0)continue;
            int n=s.length()/k;
            n--;
            int start=k;
            while(n && start<=s.length()-k){
                if(!compare(s.substr(0, k), s.substr(start, k))) break;
                start+=k;
                n--;
            }
            //cout<<", "<<n;
            if(n==0) return k;
        }
        return s.length();
    }
};