class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int n = words.size();
        int m = words[0].size();
        vector<int> ans;
        if(s.length() < (n*m)) return ans;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[words[i]]++;
        }
        for (int i = 0; i <= (s.length() - (n * m)); i++)
        {
            unordered_map<string, int> temp = mp;
            int flag = 0;
            for (int j = i; j <= i + (n * m); j += m)
            {
                if ((j + m) <= s.length())
                {
                    string a = s.substr(j, m);
                    if (temp[a] == 0)
                    {
                        break;
                    }
                    temp[a]--;
                    flag++;
                }
            }
            if (flag == n)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};