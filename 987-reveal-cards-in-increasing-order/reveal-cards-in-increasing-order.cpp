class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(),deck.rend());
        deque<int> dq;
        int n = deck.size();
        dq.push_back(deck[0]);
        for(int i = 1 ; i<n ; i++){
            int back = dq.back();
            dq.pop_back();
            dq.push_front(back);
            dq.push_front(deck[i]);
        }
        vector<int> ans;
        for(auto i : dq) ans.push_back(i);

        return ans; 
    }
};