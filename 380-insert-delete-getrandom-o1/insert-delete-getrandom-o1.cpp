class RandomizedSet {
    unordered_map<int,int> mp;
    vector<int> v;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
       if(mp.find(val) == mp.end()) return false;
       int i = mp[val];
       mp[v.back()] = i; 
       // transfering this index element to last 
       swap(v[i] , v[v.size()-1]);
       v.pop_back(); // removing the val from the array 
       mp.erase(val); // removing val from map
       return true; 
    }
    
    int getRandom() {
        /** if a number is divided by k then the 
        domain of remainders will be defined from [0,k-1];
        **/
        return v[rand()%(v.size())]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */