class RandomizedSet {
    std::set<int> s;
    std::vector<int> elements;  // Additional vector to store elements
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(s.find(val) != s.end()) return false;
        s.insert(val);
        elements.push_back(val);  // Add to the vector as well
        return true;
    }
    
    bool remove(int val) {
        auto it = s.find(val);
        if(it == s.end()) return false;

        s.erase(it);
        elements.erase(std::remove(elements.begin(), elements.end(), val), elements.end());  // Remove from the vector
        return true; 
    }
    
    int getRandom() {
        if (elements.empty()) {
            // Handle the case when the set is empty
            // You might want to throw an exception or return a default value
        }

        // Use a random index to get an element from the vector
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, elements.size() - 1);

        int randomIndex = dis(gen);
        return elements[randomIndex];
    }
};