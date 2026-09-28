class Solution {
public:
class Trienode{
    public: 
    char data ; 
    unordered_map<char, Trienode*> children;
    bool isTerminal;
    int childcount; 

    Trienode( char val){
        data = val ; 
        isTerminal = false ;
        childcount = 0 ; 
    }
};
void insertword( Trienode* root , string word){

    if( word.length() == 0){
      root->  isTerminal = true ;
        return ;
    }
    char ch = word[0];
    Trienode* child ; 
    if( root-> children.find(ch) != root-> children.end()){
        child= root -> children[ch];

    }
    else{
        child =new Trienode(ch);
        root -> children[ch] = child ;
        root-> childcount++;
    }
    insertword( child,word.substr(1));
}
string findlcp( Trienode* root , string word ){

    string ans = "";
    if(root -> isTerminal){
        return ans ;
    }
    for( int i =0 ; i< word.length() ; i++){
        char ch = word[i];
        if( root ->childcount  == 1){
            ans.push_back(ch);
            root = root -> children[ch];
        }
        else{
            break;
        }
        if( root -> isTerminal){
            break;
        }
    }
        return ans ;
}
    string longestCommonPrefix(vector<string>& strs) {
        Trienode* root = new Trienode('-');
    //    string s = "";

        for( int i =0 ; i< strs.size() ; i++){
            string str = strs[i];
            insertword( root, str);
        } 
            string ans = findlcp( root , strs[0]);
            return ans ;
    }
};