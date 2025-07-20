class Solution {
public:
    // Trie
    struct Node {
        int childNum;
        int mark;
        map<string, Node> child;
        Node() {
            childNum = 0;
            mark = false;
        }
    };
    struct Trie {
        Trie() {}
        void AddList(vector<string>& path) {
            Node* temp = &root;
            for (string &s:path) {
                if (temp->child.find(s) == temp->child.end()){
                    temp->child[s] = Node();
                    ++temp->childNum;
                }
                temp = &temp->child[s];
            }
        }
        
        string _RecurRecord(Node& node) {
            if (!node.childNum) return "";
            // update occ (hashing)
            string hash = "";
            for (auto& it: node.child) {
                string out = "(" + it.first + _RecurRecord(it.second) + ")";
                hash += out;
            }
            ++occ[hash];
            return hash;
        }

        string _RecurMark(Node& node) {
            if (!node.childNum) return "";
            // update occ (hashing)
            // format: ((child1)(child2))
            string hash = "";
            for (auto& it: node.child) {
                string out = "(" + it.first + _RecurMark(it.second) + ")";
                hash += out;
            }
            if (occ[hash] > 1){
                node.mark = true;
            }
            return hash;
        }
        void _RecurOut(Node& node, vector<vector<string>>& out) {
            for (auto& it: node.child) {
                if (it.second.mark) continue;
                temp.push_back(it.first);
                out.push_back(temp);
                _RecurOut(it.second, out);
                temp.pop_back();
            }
        }

        void Solve(vector<vector<string>>& out) {
            _RecurRecord(root);
            _RecurMark(root);
            _RecurOut(root, out);
        }

        map<string, int> occ;
        vector<string> temp;
        Node root;
    };

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // unordred_map: store subpath
        Trie trie;
        for (vector<string>& p:paths){
            trie.AddList(p);
        }
        vector<vector<string>> out;
        trie.Solve(out);
        return out;
    }
};