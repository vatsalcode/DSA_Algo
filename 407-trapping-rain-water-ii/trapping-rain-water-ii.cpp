class Solution {
public:
    // Define a structure to store cell information
    struct Cell {
        int x, y, height;
        // Constructor to initialize cell coordinates and height
        Cell(int x, int y, int height) : x(x), y(y), height(height) {}
    };

    // Comparator for the priority queue (min-heap) to compare cells based on height
    struct Compare {
        bool operator()(const Cell &a, const Cell &b) {
            return a.height > b.height;
        }
    };

    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<Cell, vector<Cell>, Compare> pq;

        // Add all boundary cells to the priority queue
        for (int i = 0; i < m; ++i) {
            pq.push(Cell(i, 0, heightMap[i][0]));
            pq.push(Cell(i, n - 1, heightMap[i][n - 1]));
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            pq.push(Cell(0, j, heightMap[0][j]));
            pq.push(Cell(m - 1, j, heightMap[m - 1][j]));
            visited[0][j] = visited[m - 1][j] = true;
        }

        // Directions array for moving in 4 directions
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int waterTrapped = 0;

        // Process cells in the priority queue
        while (!pq.empty()) {
            Cell cell = pq.top();
            pq.pop();
            // Check all 4 possible directions
            for (int i = 0; i < 4; ++i) {
                int x = cell.x + directions[i][0];
                int y = cell.y + directions[i][1];
                // If the cell is within bounds and not visited
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                    // Calculate trapped water at this cell
                    waterTrapped += max(0, cell.height - heightMap[x][y]);
                    // Add the neighbor cell to the heap with updated height
                    pq.push(Cell(x, y, max(cell.height, heightMap[x][y])));
                    visited[x][y] = true;
                }
            }
        }

        return waterTrapped;
    }
};