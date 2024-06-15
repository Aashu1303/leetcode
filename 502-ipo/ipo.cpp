typedef pair<int,int> pii;
#define all(x) (x).begin() , (x).end()
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<pii> pq;
        vector<pii> v;
        for(int i = 0 ; i < n ; i++){
            v.push_back({capital[i] , profits[i]});
        }
        sort(v.begin() , v.end());
        // for(auto i : s){
        //     cout << i.first << " " << i.second << endl;
        // }
        
        for(auto i : v){
            while(!pq.empty() && k > 0 && (i.first > w) && (pq.top().second <= w)){
                w += pq.top().first;
                k--;
                pq.pop();
            }
            pq.push({i.second , i.first});
        }   

        while(!pq.empty() && k > 0 && w >= pq.top().second){
            w += pq.top().first;
            pq.pop();
            k--;
        }

        return w;
    }
};