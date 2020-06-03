class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = [0 for _ in range(len(nums))]
        ans = 0
        for x in nums:
            l, r = 0, ans
            while l != r:
                mid = l + (r-l)//2
                if dp[mid] < x:
                    l = mid + 1
                else:
                    r = mid
            dp[l] = x
            ans = max(ans, l + 1)
        return ans