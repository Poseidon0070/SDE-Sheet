class Node{
public:
    vector<Node*> link;
    bool end;
    Node(){
        this->link.assign(26,nullptr);
        this->end = false;
    }
    bool has(char c){
        return this->link[c-'a'] != nullptr;
    }
    void put(char c){
        this->link[c-'a'] = new Node();
        return ;
    }
    Node* move(char c){
        return this->link[c-'a'];
    }
};

class WordDictionary {
private:
    Node* head;
public:
    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        Node* curr = head;
        for(int i=0;i<word.size();i++){
            if(!curr->has(word[i])){
                curr->put(word[i]);
            }
            curr = curr->move(word[i]);
        }
        curr->end = true;
    }

    bool isPresent(int i,Node* curr, string &s){
        if(i == s.size()){
            return curr->end;
        }
        int ans = 0;
        if(s[i] != '.'){
            if(!curr->has(s[i])){
                return false;
            }
            curr = curr->move(s[i]);
            ans |= isPresent(i+1,curr,s);
        }else{
            for(int j=0;j<26;j++){
                if(curr->has('a'+j)){
                    Node* temp = curr->move('a'+j);
                    ans |= isPresent(i+1,temp,s);
                }
            }
        }
        return ans;
        // return false;
    }
    
    bool search(string word) {
        Node* curr = head;
        return isPresent(0,curr,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */