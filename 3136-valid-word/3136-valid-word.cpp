class Solution {
public:
    bool isVowel(char& c) {
        if (isupper(c)){
            return c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
        }else{
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        }
        return false;
    }
    bool isValid(string word) {
        if (word.size()<3) return false;
        int vowel=0, consonant=0;
        for (char& c:word){
            if (isalpha(c)){
                if (isVowel(c)){
                    vowel=true;
                }else{
                    consonant=true;
                }
            }else if (!isdigit(c)){
                return false;
            }
        }
        if (consonant&&vowel) return true;
        return false;
    }
};