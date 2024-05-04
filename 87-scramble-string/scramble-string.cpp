class Solution {
public:
   string createKey(const string& s1, const string& s2) {
    return s1 + "," + s2;  // Use a comma to separate the two strings uniquely
}

// Function to determine if s2 is a scrambled version of s1 using memoization
bool isScrambleHelper(const string& s1, const string& s2, unordered_map<string, bool>& memo) {
    string key = createKey(s1, s2);  // Create a unique key for the current substring pair
    if (memo.count(key)) return memo[key];  // Return the stored result if already computed

    if (s1 == s2) {
        memo[key] = true;
        return true;
    }
    if (s1.length() != s2.length()) {
        memo[key] = false;
        return false;
    }

    string t1 = s1, t2 = s2;
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    if (t1 != t2) {
        memo[key] = false;
        return false;
    }

    int n = s1.length();
    for (int i = 1; i < n; i++) {
        if ((isScrambleHelper(s1.substr(0, i), s2.substr(0, i), memo) && isScrambleHelper(s1.substr(i), s2.substr(i), memo)) ||
            (isScrambleHelper(s1.substr(0, i), s2.substr(n - i), memo) && isScrambleHelper(s1.substr(i), s2.substr(0, n - i), memo))) {
            memo[key] = true;
            return true;
        }
    }
    memo[key] = false;
    return false;
}

bool isScramble(const string& s1, const string& s2) {
    unordered_map<string, bool> memo;  // Memoization map
    return isScrambleHelper(s1, s2, memo);
}


};