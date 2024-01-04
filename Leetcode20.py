class Solution:
    def isValid(self, s: str) -> bool:
        openings = []
        for i in s:
            if i == "(" or i == "[" or i == "{":
                openings.append(i)
                continue
            if len(openings) == 0:
                return False

            if i == ")" and openings[-1] == "(":
                openings.pop(-1)
            elif i == ")":
                return False
            
            if i == "]" and openings[-1] == "[":
                openings.pop(-1)
            elif i == "]":
                return False
            
            if i == "}" and openings[-1] == "{":
                openings.pop(-1)
            elif i == "}":
                return False

        if len(openings) != 0:
            return False
        return True 
