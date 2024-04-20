class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        seenLand = [[False for _ in range(len(land[0]))] for _ in range(len(land))]
        farmland = []

        def getFarmCoord(index):
            x, y = index
            x1, y1 = index
            while(x<len(land[0]) and land[y][x]==1):
                x += 1
            x2 = x-1
            while(y<len(land) and land[y][x2]==1):
                for i in range(x1, x):
                    seenLand[y][i] = True
                y += 1
            y2 = y-1
            return [y1, x1, y2, x2]
