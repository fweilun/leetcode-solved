class Solution {
public:
    class Node{
    public:
        int endFor=0;
        int childCount=0;
        Node* child[26];
        Node(){
            endFor=0;
            childCount=0;
            memset(child, 0, sizeof(child));
        }
    };

    int n, m;
    vector<vector<int>> vis;
    vector<string> out;
    vector<string> all_words;
    void dfs(vector<vector<char>>& board,int x,int y,Node* node){
        if (node->endFor){
            out.push_back(all_words[node->endFor-1]);
            node->endFor=0;
        }
        if (x<0||x>=n||y<0||y>=m||vis[x][y]) return;
        vis[x][y]=true;
        int target=board[x][y]-'a';
        Node* next=node->child[target];
        if (next){
            dfs(board, x+1, y, next);
            dfs(board, x, y+1, next);
            dfs(board, x-1, y, next);
            dfs(board, x, y-1, next);
        }
        vis[x][y]=false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Node* root=new Node();
        Node* temp;
        for (int i=0;i<words.size();i++){
            temp=root;
            for (char&c:words[i]){
                if (!temp->child[c-'a']){
                    Node* next=new Node();
                    temp->child[c-'a']=next;
                    temp->childCount++;
                }
                temp=temp->child[c-'a'];
            }
            temp->endFor=i+1;
        }


        n=board.size();
        m=board[0].size();
        vis=vector<vector<int>>(n, vector<int>(m, 0));
        all_words=words;
        for (int x=0;x<n;x++){
            for (int y=0;y<m;y++){
                dfs(board, x, y, root);
            }
        }
        return out;
    }
};