class Solution(object):
    def longestMonotonicSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        inc_cum = 1
        dec_cum = 1
        inc_max_cum = 1
        dec_max_cum = 1
        for i in range(1, n):
            if nums[i] > nums[i-1]:
                inc_cum+=1
            else:
                inc_max_cum = max(inc_max_cum, inc_cum)
                inc_cum=1

            if nums[i] < nums[i-1]:
                dec_cum+=1
            else:
                dec_max_cum = max(dec_max_cum, dec_cum)
                dec_cum=1
        inc_max_cum = max(inc_max_cum, inc_cum)
        dec_max_cum = max(dec_max_cum, dec_cum)
        return max(inc_max_cum, dec_max_cum)
        