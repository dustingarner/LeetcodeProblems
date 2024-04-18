class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        seenSquares = [[False for x in grid[0]] for y in grid]

        def getPerimeter(index, currentPerimeter=0):
            y, x = index
            if grid[y][x]==0:
                return currentPerimeter
            if seenSquares[y][x]:
                return currentPerimeter
            seenSquares[y][x] = True
            currentPerimeter += 4

            north = False if y<=0 else seenSquares[y-1][x]
            south = False if y>=len(grid)-1 else seenSquares[y+1][x]
            west = False if x<=0 else seenSquares[y][x-1]
            east = False if x>=len(grid[0])-1 else seenSquares[y][x+1]

            if x>0 and west:
                currentPerimeter -= 2
            elif x>0:
                currentPerimeter = getPerimeter([y, x-1], currentPerimeter)
            
            if x<len(grid[0])-1 and east:
                currentPerimeter -= 2
            elif x<len(grid[0])-1:
                currentPerimeter = getPerimeter([y, x+1], currentPerimeter)
            
            if y>0 and north:
                currentPerimeter -= 2
            elif y>0:
                currentPerimeter = getPerimeter([y-1, x], currentPerimeter)
            
            if y<len(grid)-1 and south:
                currentPerimeter -= 2
            elif y<len(grid)-1:
                currentPerimeter = getPerimeter([y+1, x], currentPerimeter)
            
            return currentPerimeter

        endLoop = False
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]==1:
                    endLoop = True
                    break
            if endLoop:
                break
        
        return getPerimeter([i, j])

