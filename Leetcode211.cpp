struct Node {
    char letter;
    Node* nextNodes[26] = {};
    bool wordEnd = false;

    Node(char _letter) {
        letter = _letter;
    }

    ~Node() {
        for(auto x : nextNodes){
            if(x==nullptr){continue;}
            delete x;
        }
    }

    void addWord(string& word, int index){
        if(index==word.length()){
            wordEnd = true;
            return;
        }
        int letterInd = word[index]-'a';
        if(nextNodes[letterInd]==nullptr){
            nextNodes[letterInd] = new Node(word[index]);
        }
        nextNodes[letterInd]->addWord(word, index+1);
    }

    bool search(string& word, int index){
        if(index==word.length()){return wordEnd;}
        if(word[index]=='.'){
            bool anyContains = false;
            for(auto x : nextNodes){
                if(x==nullptr){continue;}
                if(x->search(word, index+1)){
                    anyContains = true;
                    break;
                }
            }
            return anyContains;
        }
        int letterInd = word[index]-'a';
        if(nextNodes[letterInd]==nullptr){return false;}
        return nextNodes[letterInd]->search(word, index+1);
    }
};

class WordDictionary {
public:
    Node* node;

    WordDictionary() {
        node = new Node('0');
    }

    ~WordDictionary() {
        delete node;
    }
    
    void addWord(string word) {
        node->addWord(word, 0);
    }
    
    bool search(string word) {
        return node->search(word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
