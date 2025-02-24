

class Trie {
    typedef struct _TreeNode {
        char val;
        int isend=false;
        _TreeNode* child[26];
        _TreeNode(char val) {
            this->val = val;
            for (int i = 0; i < 26; ++i) {
                child[i] = nullptr;
            }
        }
    } TreeNode;

public:
    TreeNode* root;
    Trie() {
        root = new TreeNode('@');
    }
    
    void insert(string word) {
        TreeNode* temp=root;
        for (char& c:word){
            if(!temp->child[c-'a']){
                TreeNode* to_add=new TreeNode(c);
                temp->child[c-'a']=to_add;
            }
            temp=temp->child[c-'a'];
        }
        temp->isend=true;
    }
    
    bool search(string word) {
        TreeNode* temp=root;
        for (int i=0;i<word.size();i++){
            if (temp->child[word[i]-'a']){
                temp=temp->child[word[i]-'a'];
            }else{
                return false;
            }
        }
        return temp->isend;
    }
    
    bool startsWith(string prefix) {
        TreeNode* temp=root;
        for(char &c:prefix){
            if (temp->child[c-'a']){
                temp=temp->child[c-'a'];
            }else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */