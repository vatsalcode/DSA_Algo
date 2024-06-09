class Solution {
public:
    vector<vector<string>> helper(vector<string>& strs){
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>m;
        for(auto c:strs)
        {
            string t=c;
            sort(t.begin(),t.end()); // to find groupAnagrams
            m[t].push_back(c);
        }
        for(auto i :m){
            ans.push_back(i.second);
        }

        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return helper(strs);
    }
};