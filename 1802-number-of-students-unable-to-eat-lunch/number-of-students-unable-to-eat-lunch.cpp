class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sa) {
        int i = 0, j = 0 , n = sa.size();
        int count = 0;
        while((j < n) && (count != n-j+1)){
            if(st[i] == sa[j]){
                count = 0;
                i++;
                j++;
            }else{
                st.push_back(st[i]);
                i++;
                count++;
            }
        }

        return n-j;
    }
};