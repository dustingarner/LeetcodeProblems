class Solution:
    def testValues(self, quotients, startArr, goalValue):
        startValue = startArr[-1]
        if goalValue in quotients[startValue]:
            return startArr + [goalValue]
        for i in quotients[startValue]:
            if i in startArr:
                continue
            tempArr = startArr + [i]
            valChain = self.testValues(quotients, tempArr, goalValue)
            if valChain[-1] == goalValue:
                return valChain
        return startArr

    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        quotients = {}

        for i, j in zip(equations, values):
            a = i[0]
            b = i[1]
            if a not in quotients:
                quotients[a] = {a: 1.0}
            quotients[a][b] = j

            if b not in quotients:
                quotients[b] = {b: 1.0}
            quotients[b][a] = 1/j
          
        endValues = []
        #print(quotients)
        for i in queries:
            a = i[0]
            b = i[1]
            value = -1
            if not a in quotients or not b in quotients:
                endValues += [value]
                continue
            valArr = self.testValues(quotients, [a], b)
            if valArr[-1] != b:
                endValues += [value]
                continue
            value = 1
            #print(valArr)
            for j, k in zip(valArr[0:-1], valArr[1:]):
                value *= quotients[j][k]
            endValues += [value]
        return endValues
