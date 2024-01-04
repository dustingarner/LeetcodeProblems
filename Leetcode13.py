class Solution(object):
    def romanToInt(self, s):
        conversion = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        value = 0
        for indi, i in enumerate(s):
            value += conversion[i]
            if indi == 0:
                continue
            if conversion[i] > conversion[s[indi - 1]]:
                prev_num = conversion[s[indi - 1]]
                value -= prev_num * 2
        return value
