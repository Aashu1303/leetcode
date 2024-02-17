class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int n = h.size();
        priority_queue<int , vector<int>, greater<int>> pq;
        int i;
        for(i = 0 ; i < n-1 ; i++){
            int curr = h[i+1] - h[i];
            if(curr > 0){
                pq.push(curr);
                if(pq.size() > l){
                    b -= pq.top();
                    pq.pop();
                    
                    if(b < 0) return i;
                }
            }
        }

        return n-1;
    }
};