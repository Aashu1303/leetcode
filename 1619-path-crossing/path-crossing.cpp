struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Simple hash combining technique
        return h1 ^ h2;
    }
};
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<pair<int,int>,int , pair_hash> mp;
        int x = 0 , y = 0;
        mp[{0,0}]++;
        for(auto i : path){
            if(i == 'N'){
                y++;
            }else if(i == 'S'){
                y--;
            }else if(i == 'W'){
                x--;
            }else{
                x++;
            }
            
            if(mp[{x,y}] != 0){
                return true;
            }
            mp[{x,y}]++;
        }

        return false;
    }
};