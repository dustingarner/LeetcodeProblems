class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> seenSteps;
        return numberSteps(n, seenSteps);
    }

    int numberSteps(int n, unordered_map<int, int>& seenSteps){
        if(seenSteps.find(n) != seenSteps.end()){
            return seenSteps[n];
        }
        if(n < 1) {return 0;}
        if(n == 1){return 1;}
        if(n == 2){return 2;}
        int steps = 0;
        steps += numberSteps(n-1, seenSteps);
        steps += numberSteps(n-2, seenSteps);
        seenSteps[n] = steps;
        return steps;
    }
};
