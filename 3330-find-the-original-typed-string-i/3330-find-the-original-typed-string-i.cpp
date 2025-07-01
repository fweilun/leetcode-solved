class Solution {
public:
    int possibleStringCount(string word) {
        word.push_back('#');
        int counter=0, out=0;
        char temp='@';
        for (char &c:word){
            if (temp==c){
                counter++;
            }else{
                temp=c;
                out+=counter;
                counter=0;
            }
        }
        return 1+out;
    }
};