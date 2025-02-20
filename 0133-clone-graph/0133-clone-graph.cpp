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
    vector<Node*> vis;
    void dfs(Node* node, Node* out){
        if (node==nullptr) return;
        out->val = node->val;
        vis[node->val] = out;
        for (Node* child:node->neighbors){
            if (vis[child->val]) {
                out->neighbors.push_back(vis[child->val]);
                continue;
            }
            Node* cpy_child = new Node();
            out->neighbors.push_back(cpy_child);
            dfs(child, cpy_child);
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node* out = new Node();
        vis = vector<Node*>(101, nullptr);
        dfs(node, out);
        return out;
    }

};