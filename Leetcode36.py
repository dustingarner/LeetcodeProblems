class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in board:
            numbers_found = [False] * 9
            for j in i:
                if j == ".":
                    continue
                index = int(j) - 1
                if numbers_found[index]:
                    return False
                numbers_found[index] = True
        
        for i in range(9):
            numbers_found = [False] * 9
            for j in board:
                if j[i] == ".":
                    continue
                index = int(j[i]) - 1
                if numbers_found[index]:
                    return False
                numbers_found[index] = True
        
        for i in range(3):
            for j in range(3):
                numbers_found = [False] * 9
                for k in range(3):
                    for l in range(3):
                        indh = k + (3*i)
                        indv = l + (3*j)
                        number = board[indv][indh]
                        if number == ".":
                            continue
                        index = int(number) - 1
                        if numbers_found[index]:
                            return False
                        numbers_found[index] = True
        
        return True
