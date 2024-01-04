class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        bases = set([x for x in range(n)])
        for i in edges:
            if i[1] in bases:
                bases.remove(i[1])
        return bases
