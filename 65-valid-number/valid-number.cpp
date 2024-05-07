class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.length();

    while (i < n && isspace(s[i])) i++;


    if (i < n && (s[i] == '+' || s[i] == '-')) i++;

    bool hasDigits = false, hasDot = false;

    // Base number parsing
    for (; i < n && (isdigit(s[i]) || s[i] == '.'); i++) {
        if (isdigit(s[i])) hasDigits = true;
        if (s[i] == '.') {
            if (hasDot) return false;  
            hasDot = true;
        }
    }

     
    if (i < n && (s[i] == 'e' || s[i] == 'E')) {
        i++;   
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;   

        bool hasExpDigits = false;
        for (; i < n && isdigit(s[i]); i++) hasExpDigits = true;
        if (!hasExpDigits) return false;
    }

 
    while (i < n && isspace(s[i])) i++;
 
    return i == n && hasDigits;
    }
};