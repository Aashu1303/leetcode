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
        
        // every time the current capital is greater than w , we need to take all the previous maxm capitals profits until the w will be greater than the curr 
        for(auto i : v){
            while(!pq.empty() && k > 0 && (i.first > w) && (pq.top().second <= w)){
                w += pq.top().first;
                k--;
                pq.pop();
            }
            pq.push({i.second , i.first});
        }   


        // at last we need to take the rest of the elements from which w is greater in capital
        while(!pq.empty() && k > 0 && w >= pq.top().second){
            w += pq.top().first;
            pq.pop();
            k--;
        }

        return w;
    }
};