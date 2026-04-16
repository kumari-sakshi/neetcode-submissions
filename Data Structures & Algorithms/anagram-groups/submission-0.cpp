class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string ,vector<string>>m;
        for(auto s: strs)
        { 
            string temp = s;
             sort(temp.begin(),temp.end());
            m[temp].push_back(s);
        }
        vector<vector<string>> sol;
        for(auto s: m)
        {
            sol.push_back(s.second);
        }
        return sol;
        
    }
};
