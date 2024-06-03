public class Solution {
    public int AppendCharacters(string s, string t) {
        int m=s.Length,n=t.Length;
        int i=0,j=0;
        while(i<m &&j<n){
            if(s[i]==t[j]){
                j++;
            }
            i++;
        }

        return n-j;
    }
}