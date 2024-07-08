class Solution {
public:
    int findTheWinner(int n, int k, int start=1) {
        if(n == 1){return 1;}
        int removed = (start + k - 1) % n;
        int nextStart = removed == 0 ? 1 : removed;
        int winner = findTheWinner(n-1, k, nextStart);
        if(removed == 0){removed = n;}
        if(winner >= removed){return winner + 1;}
        return winner;
    }
};
