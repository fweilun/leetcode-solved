class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n){
            if (n%3==2) return false;
            else if (n%3==1) n-=1;
            else n/=3;
        }
        return true;
    }
};