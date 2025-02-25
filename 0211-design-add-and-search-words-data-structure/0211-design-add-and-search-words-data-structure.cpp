class Node{
public:
    bool isEnd=false;
    Node* child[26];
    Node(){
        for (int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* temp=root;
        for (char& x:word){
            x-='a';
            if (!temp->child[x]){
                temp->child[x]=new Node();
            }
            temp=temp->child[x];
        }
        temp->isEnd=true;
    }
    bool dfs(char* c, Node* temp){
        if (*c=='\0') return temp->isEnd;
        else if (*c=='.'){
            for (int i=0;i<26;i++){
                if (temp->child[i] && dfs(c+1, temp->child[i])){
                    return true;
                }
            }
        }else if (temp->child[*c-'a']){
            return dfs(c+1, temp->child[*c-'a']);
        }
        return false;
    }
    bool search(string word) {
        Node* temp=root;
        
        return dfs(&word[0], temp);
    }
};