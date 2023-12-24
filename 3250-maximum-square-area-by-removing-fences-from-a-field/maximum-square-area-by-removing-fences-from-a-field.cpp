class Solution {
     unordered_set<int> make(vector<int> &v, int p) {
         v.push_back(1);
         v.push_back(p);
         unordered_set<int> s;
         for (int i = 0; i < v.size(); ++i) {
             for (int j = 0; j < i; ++j) {
                 s.insert(abs(v[i] - v[j]));  
             }
         }
        return s;
    }
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const auto& s = make(hFences, m);
        vFences.push_back(1);
        vFences.push_back(n);
        int e = 0;
        for (int i = 0; i < vFences.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                const int x = abs(vFences[i] - vFences[j]);
                if (x > e && s.count(x)) {
                    e = x;
                }
            }
            
        }
        return e ? (1LL * e * e) % 1000000007 : -1;
        
    }
};