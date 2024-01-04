class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        if len(s) == 1:
            return -1
        char_first_pos = {}
        doubled_chars = False
        max_length = 0
        for indi, i in enumerate(s):
            if not i in char_first_pos:
                char_first_pos[i] = indi
                continue
            doubled_chars = True
            temp_length = indi - char_first_pos[i] - 1
            max_length = max(temp_length, max_length)
        if not doubled_chars:
            return -1
        return max_length
            
