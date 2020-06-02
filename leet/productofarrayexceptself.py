class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0 for _ in range(n)]
        ans[0] = 1
        for i in range(1, n):
            ans[i] = ans[i-1]*nums[i - 1]
        r = 1
        for i in range(n-1, -1, -1):
            ans[i] = r*ans[i]
            r *= nums[i]
        return ans