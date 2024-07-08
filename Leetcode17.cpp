class Solution {
public:
    vector<string> letterCombinations(string digits, int index = 0) {
        unordered_map <char, string> mapping;
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";
        vector<string> combos;
        makeCombos(digits, 0, combos, mapping);
        return combos;
    }

    void makeCombos(string& digits, int index, vector<string>& combos, unordered_map <char, string>& mapping){
        if(digits.length() == 0){return;}
        if(index == digits.length() - 1){
            for(auto x : mapping[digits[index]]){
                combos.push_back(string (1, x));
            }
            return;
        }
        makeCombos(digits, index+1, combos, mapping);
        vector<string> newCombos;
        for(int i = 0; i < combos.size(); ++i){
            string word = combos[i];
            for(int j = 0; j < mapping[digits[index]].length(); ++j){
                char letter = mapping[digits[index]][j];
                if(j == 0){
                    combos[i] = letter + word;
                }
                else{
                    newCombos.push_back(letter + word);
                }
            }
        }
        combos.insert(combos.end(), newCombos.begin(), newCombos.end());
    }
};
