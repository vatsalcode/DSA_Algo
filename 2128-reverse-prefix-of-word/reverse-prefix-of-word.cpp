class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans="";
        int ind=-1;
        for(int i=0;i<word.size();i++){
            ans+=word[i];
            if(word[i]==ch){
                ind=i;
                break;
            }
        }
        if(ind!=-1){
            reverse(ans.begin(), ans.end());
            for(int i=ind+1;i<word.size();i++){
                ans+=word[i];
            }
        }else{
            return word;
        }

        return ans;
    }
};