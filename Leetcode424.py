class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l, r = 0, 0
        char_dict = defaultdict(int)
        max_char = 0
        max_length = 0
        for indi, i in enumerate(s):
            char_dict[s[r]] += 1
            max_char = char_dict[s[r]] if char_dict[s[r]] > max_char else max_char
            while(r - l + 1 - max_char > k):
                char_dict[s[l]] -= 1
                l += 1
            max_length = max(max_length, r - l + 1)
            r += 1
        return max_length

