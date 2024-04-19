class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        seenPlots = [[False for x in range(len(grid[0]))] for y in range(len(grid))]
        
        def markIsland(index):
            x, y = index
            seenPlots[y][x] = True

            if x>0 and grid[y][x-1]=="1" and not seenPlots[y][x-1]:
                markIsland([x-1, y])
            if x<len(grid[0])-1 and grid[y][x+1]=="1" and not seenPlots[y][x+1]:
                markIsland([x+1, y])
            if y>0 and grid[y-1][x]=="1" and not seenPlots[y-1][x]:
                markIsland([x, y-1])
            if y<len(grid)-1 and grid[y+1][x]=="1" and not seenPlots[y+1][x]:
                markIsland([x, y+1])
            
        islandCount = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]=="1" and not seenPlots[i][j]:
                    markIsland([j, i])
                    islandCount += 1
        return islandCount
