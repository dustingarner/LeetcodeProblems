class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        current_row = {}
        arr = []
        for i in nums:
            if not i in current_row:
                current_row[i] = 0
            if len(arr) <= current_row[i]:
                arr.append([i])
            else:
                arr[current_row[i]].append(i)
            current_row[i] += 1
        return arr
