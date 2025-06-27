class Bitset {
public:
    Bitset(int size) {
        bits = string(size, '0');
        n=size;
        one_cnt = 0;
        flipped=false;
    }
    
    void fix(int idx) {
        if (bits[idx] != '1' - flipped) {
            bits[idx] = '1' - flipped;
            ++one_cnt;
        }
    }

    void unfix(int idx) {
        if (bits[idx] != '0' + flipped) {
            bits[idx] = '0' + flipped;
            --one_cnt;
        }
    }
    
    void flip() {
        flipped = !flipped;
        one_cnt = n - one_cnt;
    }
    
    bool all() {
        return one_cnt==n;
    }
    
    bool one() {
        return one_cnt;
    }
    
    int count() {
        return one_cnt;
    }
    
    string toString() {
        string res = bits;
        if (flipped) {
            for (char &c : res) {
                c = (c == '0') ? '1' : '0';
            }
        }
        return res;
    }

    string bits;
    int n, one_cnt;
    bool flipped;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */