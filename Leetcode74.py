class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l = 0
        r = len(matrix[0])
        u = 0
        d = len(matrix)
        horiz_length = len(matrix[0])
        row = -1

        while(u < d):
            n = ((d - u) // 2) + u
            if matrix[n][horiz_length - 1] >= target and \
                    matrix[n][0] <= target:
                row = n
                break
            if matrix[n][horiz_length - 1] < target:
                u = n + 1
            if matrix[n][0] > target:
                d = n
            row = d
        
        if row >= len(matrix):
            return False
        if matrix[row][0] > target:
            return False
        if matrix[row][horiz_length - 1] < target:
            return False

        while(l < r):
            m = ((r - l) // 2) + l
            if matrix[row][m] == target:
                return True
            if matrix[row][m] < target:
                l = m + 1
            elif matrix[row][m] > target:
                r = m
        return False
            
            
