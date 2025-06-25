class Solution {
public:
    int mergeSort(vector<int>& nums, int s, int e) {
        if (s + 1 >= e) return 0;
        int mid = (s + e) / 2;
        int inv = mergeSort(nums, s, mid) + mergeSort(nums, mid, e);

        vector<int> tmp(e - s);
        int i = s, j = mid, idx = 0;
        while (i < mid && j < e) {
            if (nums[i] <= nums[j]) {
                tmp[idx++] = nums[i++];
            } else {
                tmp[idx++] = nums[j++];
                inv += mid - i;
            }
        }
        while (i < mid) tmp[idx++] = nums[i++];
        while (j < e)  tmp[idx++] = nums[j++];
        for (int k = 0; k < e - s; ++k) nums[s + k] = tmp[k];

        return inv;
    }

    vector<int> makeTarget(const vector<int>& nums, bool start_with_odd) {
        int odd_pos = start_with_odd ? 0 : 1;
        int even_pos = start_with_odd ? 1 : 0;
        vector<int> target(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2) {
                target[i] = odd_pos;
                odd_pos += 2;
            } else {
                target[i] = even_pos;
                even_pos += 2;
            }
        }
        return target;
    }

    int minSwaps(vector<int>& nums) {
        int odd = 0, even = 0;
        for (int x : nums) {
            (x % 2) ? ++odd : ++even;
        }

        if (abs(odd - even) > 1) return -1;

        int n = nums.size();
        if (odd == even) {
            auto t1 = makeTarget(nums, true);
            auto t2 = makeTarget(nums, false);
            return min(mergeSort(t1, 0, n), mergeSort(t2, 0, n));
        }

        bool start_with_odd = (odd > even);
        auto target = makeTarget(nums, start_with_odd);
        return mergeSort(target, 0, n);
    }
};