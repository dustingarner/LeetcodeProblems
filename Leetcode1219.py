class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        def getPath(coord):
            y, x = coord
            if grid[y][x] == 0:
                return 0
            
            value = grid[y][x]
            grid[y][x] = 0
            
            path = 0
            for i in range(4):
                if i == 0 and y > 0:
                    tempCoord = [y-1, x]
                elif i == 0:
                    continue
                if i == 1 and y < len(grid)-1:
                    tempCoord = [y+1, x]
                elif i == 1:
                    continue
                if i == 2 and x > 0:
                    tempCoord = [y, x-1]
                elif i == 2:
                    continue
                if i == 3 and x < len(grid[y])-1:
                    tempCoord = [y, x+1]
                elif i == 3:
                    continue
                tempPath = getPath(tempCoord)
                path = max(path, tempPath)
            grid[y][x] = value
            return value + path

        maxValue = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                value = getPath([i, j])
                maxValue = max(value, maxValue)
        return maxValue

