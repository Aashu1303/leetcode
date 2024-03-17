class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int start = newInterval[0];
        int end = newInterval[1];
        bool f = true;
        for(int i = 0 ; i < intervals.size() ; i++){
            if(f && start >= intervals[i][0] && start <= intervals[i][1]){
                if(end <= intervals[i][1]){
                    f = !f;
                    ans.push_back(intervals[i]);
                    continue;
                }
                int start2 = (start > intervals[i][0]) ? intervals[i][0] : start;
                int j = i+1;
                int end2 = end;
                while(j < intervals.size() && intervals[j][0] <= end){
                    end2 = max(end2,intervals[j][1]);
                    j++;
                }
                i = j-1;
                ans.push_back({start2,end2});
                f = !f;
            }else if(f && start < intervals[i][0]){
                if(end < intervals[i][0]){
                    ans.push_back(newInterval);
                    ans.push_back(intervals[i]);
                    f = !f;
                }else{
                    int j = i;
                    while(j < intervals.size() && end >= intervals[j][0]){
                        end = max(end , intervals[j][1]);
                        j++;
                    }
                    i = j-1;
                    ans.push_back({start , end});
                    f = !f;
                }
            }else{
                ans.push_back(intervals[i]);
            }
        }

        if(f){
            ans.push_back(newInterval);
        }

        return ans;
    }
};