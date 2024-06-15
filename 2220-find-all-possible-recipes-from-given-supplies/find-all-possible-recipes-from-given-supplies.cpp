class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        unordered_map<string,int>map;
        vector<int>check_ing(n,0);

        for(auto i:supplies){
            map[i]=1;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(check_ing[j]==0){
                    int flag=1;
                    for(auto it: ingredients[j]){
                        if(map.find(it)==map.end()){
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1){
                        check_ing[j]=1;
                        map[recipes[j]]=1;
                    }
                }
            }
        }
        vector<string>ans;
        for(int i=0;i<n;i++){
            if(check_ing[i]==1){
                ans.push_back(recipes[i]);
            }
        }
        return ans;
    }
};