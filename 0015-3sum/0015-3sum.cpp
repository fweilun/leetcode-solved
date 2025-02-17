class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        cout << nums[0] << endl;
        vector<vector<int>> result;
        for (auto it = nums.begin(); it != nums.end();it++){
            
            auto its = it+1;
            auto ite = nums.end()-1;
            while (its < ite){
                int sm = (*it + *its + *ite);
                if (sm > 0){
                    ite--;
                }else if (sm < 0){
                    its++;
                }else{
                    int n1 = *its;
                    int n2 = *ite;
                    while (its!=nums.end() && *its == n1){its++;}
                    while (ite-1!= nums.begin() && *ite == n2){ite--;}
                    result.push_back({*it, n1, n2});
                }

            }
            while (it+1 < nums.end() && *(it+1) == *it){
                it++;
            }
        }
        return result;
    }
};