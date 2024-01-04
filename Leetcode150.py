class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in tokens:
            if i in "+-/*":
                value = stack.pop()
                if i == "+":
                    stack[-1] += value
                elif i == "-":
                    stack[-1] -= value
                elif i == "/":
                    stack[-1] /= value
                    stack[-1] = int(stack[-1])
                else:
                    stack[-1] *= value
                continue
            stack.append(int(i))
        return stack[0]
            
            
