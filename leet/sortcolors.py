class Solution:
    def sortColors(self, nums: List[int]) -> None:
        l, r = 0, len(nums)-1
        i = 0
        while l < r and i <= r:
            if nums[i] == 0:
                nums[i], nums[l] = nums[l], nums[i]
                i += 1
                l += 1
            elif nums[i] == 2:
                nums[i], nums[r] = nums[r], nums[i]
                r -= 1
            else:
                i += 1
        return nums