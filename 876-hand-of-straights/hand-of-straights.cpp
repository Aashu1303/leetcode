class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        if((n % groupSize) != 0) return false;
        map<int,int> mp;
        if(groupSize == 1) return true;
        for(auto i : hand) mp[i]++;
        int count = 0;
        while(true){
            auto it = mp.begin();
            int first = it -> first;
            // cout << "first " << first << endl;
            int second =  it -> second;
            int sz = groupSize-1;
            int curr = first;
            while(sz){
                curr++;
                if(mp[curr] == 0) break;
                mp[curr]--;
                if(mp[curr] == 0) mp.erase(curr);
                sz--;                
            }
            if(sz != 0) break;
            mp[first]--;
            count++;
            if(mp[first] == 0) mp.erase(first);
        }
        // cout << count << endl;
        if((count * groupSize) == n) return true;
        return false;
    }
};