class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = [0] * len(temperatures)
        stack = [0]
        for i in range(1, len(temperatures)):
            while(len(stack) > 0):
                if temperatures[stack[-1]] >= temperatures[i]:
                    break
                answer[stack[-1]] = i - stack[-1]
                stack.pop()
            stack.append(i)
        return answer
