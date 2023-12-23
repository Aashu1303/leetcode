class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int> mp;
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