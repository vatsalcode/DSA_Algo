class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> indegree;
        for(int i=0;i<ingredients.size();i++)
        {
            for(auto j:ingredients[i])
            {
                adj[j].push_back(recipes[i]); 
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;
        for(auto i:supplies)
        {
            q.push(i);
        }
        
        vector<string> ans;
        while(!q.empty())
        {
            string node = q.front();
            q.pop();

            for(auto i:adj[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                    ans.push_back(i); //Bcz only leaf node are supplies
                                      // all other node is recipes
                }
            }
        }
        return ans;
    }
};