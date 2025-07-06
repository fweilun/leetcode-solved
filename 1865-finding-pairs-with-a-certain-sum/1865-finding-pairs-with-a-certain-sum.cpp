class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        cpy_nums1=&nums1;
        cpy_nums2=&nums2;
        for (int &x:nums2) ++occ2[x];
    }
    
    void add(int index, int val) {
        int &x=(*cpy_nums2)[index];
        --occ2[x];
        if (!occ2[x]) occ2.erase(x);
        x+=val;
        ++occ2[x];
    }
    
    int count(int tot) {
        int cnt=0;
        for (int &x:*cpy_nums1) {
            if (occ2.find(tot-x)!=occ2.end()) {
                cnt+=occ2[tot-x];
            }
        }
        return cnt;
    }
    unordered_map<int, int> occ2;
    vector<int> *cpy_nums1, *cpy_nums2;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */