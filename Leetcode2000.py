class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        found = False
        for i in range(len(word)):
            if word[i]==ch:
                found = True
                break
        if not found:
            return word
        first_part = word[i::-1]
        second_part = "" if i==len(word)-1 else word[i+1:]
        return first_part + second_part
        
