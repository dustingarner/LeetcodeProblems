class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 1:
            return ["()"]
        below = self.generateParenthesis(n - 1)
        parenth_list = []
        for i in below:
            start = "(" + i
            stack = 0
            for j in range(1, len(start)):
                if stack == 0:
                    parenth_list.append(start[:j] + ")" + start[j:])
                if start[j] == "(":
                    stack += 1
                else:
                    stack -= 1
            parenth_list.append(start + ")")
        return parenth_list
