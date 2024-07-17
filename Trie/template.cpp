class Node{
public:
    vector<Node*> links;
    bool flg;
    Node(){
        this->links.assign(26,nullptr);
        this->flg = false;
    }
    bool has(char c){
        return (links[c-'a'] != nullptr);
    }
    void put(char c){
        links[c-'a'] = new Node();
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void set(){
        flg = true;
    }
    bool isSet(){
        return flg;
    }
};   

class Trie {
public:
    Node *root;
    Trie() {
        this->root = new Node();
    }
    
    void insert(string word) {
        Node *curr = root;
        for(int i{};i<word.size();i++){
            if(!curr->has(word[i])){
                curr->put(word[i]);
            }
            curr = curr->get(word[i]);
        }
        curr->set();
    }
    
    bool search(string word) {
        Node *curr = root;
        for(int i{};i<word.size();i++){
            if(!curr->has(word[i])) return false;
            curr = curr->get(word[i]);
        }
        return curr->isSet();
    }
    
    bool startsWith(string word) {
        Node *curr = root;
        for(int i{};i<word.size();i++){
            if(!curr->has(word[i])) return false;
            curr = curr->get(word[i]);
        }
        return true;
    }
};