class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        sorted_scores = sorted(score, reverse=True)
        ranks = {}
        for i in range(len(sorted_scores)):
            place = i + 1
            if place == 1:
                place = "Gold Medal"
            elif place == 2:
                place = "Silver Medal"
            elif place == 3:
                place = "Bronze Medal"
            ranks[sorted_scores[i]] = str(place)
        for i in range(len(score)):
            score[i] = ranks[score[i]]
        return score
