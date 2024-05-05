/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        std::queue<Node*> queue;
        queue.push(node);
        visited[node] = new Node(node->val); 

        while (!queue.empty()) {
            Node* current = queue.front();
            queue.pop();

            for (Node* neighbor : current->neighbors) {
                if (visited.find(neighbor) == visited.end()) { 
                    visited[neighbor] = new Node(neighbor->val); 
                    queue.push(neighbor);
                }
                visited[current]->neighbors.push_back(visited[neighbor]); 
            }
        }

        return visited[node];
    }
};