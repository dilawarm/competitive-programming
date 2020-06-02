class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        m, n = len(matrix), len(matrix[0])
        l, r = 0, n*m-1
        while l <= r:
            mid = l + (r - l)//2
            mid_elem = matrix[mid//n][mid%n]
            if mid_elem == target:
                return True
            elif mid_elem < target:
                l = mid + 1
            else:
                r = mid - 1
        return False