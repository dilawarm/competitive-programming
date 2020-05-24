class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        spiral = []
        
        if not matrix:
            return spiral
        
        m = len(matrix)
        n = len(matrix[0])
        
        i1 = 0
        j1 = 0
        i2 = m - 1
        j2 = n - 1
        
        while i1 <= i2 and j1 <= j2:
            for j in range(j1, j2+1):
                spiral.append(matrix[i1][j])
            
            for i in range(i1+1, i2+1):
                spiral.append(matrix[i][j2])
            
            if i1 < i2 and j1 < j2:
                for j in range(j2-1, j1-1, -1):
                    spiral.append(matrix[i2][j])
                
                for i in range(i2-1, i1, -1):
                    spiral.append(matrix[i][j1])
            
            i1 += 1
            j1 += 1
            i2 -= 1
            j2 -= 1
            
        return spiral