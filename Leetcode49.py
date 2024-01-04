class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anaDict = {}
        anagrams = []
        for i in strs:
            wordList = sorted(list(i))
            sortedWord = ""
            for j in wordList:
                sortedWord += j
            if sortedWord in anaDict:
                anagrams[anaDict[sortedWord]] += [i]
            else:
                anaDict[sortedWord] = len(anagrams)
                anagrams += [[i]]
        return anagrams
