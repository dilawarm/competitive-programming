class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = nums[0]
        fast = nums[0]
        
        slow = nums[slow]
        fast = nums[nums[fast]]
        
        while slow != fast:
            slow = nums[slow]
            fast = nums[nums[fast]]
        
        a = nums[0]
        b = slow
        
        while a != b:
            a = nums[a]
            b = nums[b]
        
        return a