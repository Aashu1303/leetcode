class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> v(n , "");
        priority_queue<pair<int,int>> pq;
        for(int i = 0 ; i < n ; i++){
            pq.push({score[i] , i});
        }

        int count = 1;
        while(!pq.empty()){
            pair<int,int> top = pq.top();
            pq.pop();
            if(count == 1){
                v[top.second] = "Gold Medal";
            }else if(count == 2){
                v[top.second] = "Silver Medal";
            }else if(count == 3){
                v[top.second] = "Bronze Medal";
            }else{
                string temp = to_string(count);
                v[top.second] = temp;
            }
            count++;
        }

        return v;
    }
};