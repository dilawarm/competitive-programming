class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = {}
        for i in range(len(nums)):
            y = target - nums[i]
            if y in res:
                j = res[y]
                if i != j:
                    return [i, j]
            else:
                res[nums[i]] = i