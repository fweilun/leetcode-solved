class Solution {
public:
    int maxDistance(string s, int k) {
        int up=0,down=0,left=0,right=0;
        int out=0;
        for (char& c:s){
            if (c=='N'){
                ++up;
            }else if (c=='S'){
                ++down;
            }else if (c=='W'){
                ++left;
            }else if (c=='E'){
                ++right;
            }
            int x=abs(left-right);
            int y=abs(up-down);
            int dx=min(left, right);
            int dy=min(up, down);
            int temp = x+y+2*(min(dx+dy, k));
            if (temp>out){
                out=temp;
            }
        }
        return out;
    }
};