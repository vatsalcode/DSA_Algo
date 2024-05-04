class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        
        for (auto i : points)
            pq.emplace(-sqrt(i[0] * i[0] + i[1] * i[1]), i);

        vector<vector<int>> ans;
        while (k-- > 0)
        {
            vector<int> a = pq.top().second;
            pq.pop();

            ans.push_back(a);
        }

        return ans;
    }
};