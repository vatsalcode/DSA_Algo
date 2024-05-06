class Solution {
public:

    vector<pair<char, int>> getGroups(const string& str) {
    vector<pair<char, int>> groups;
    int n = str.size();
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i + 1 < n && str[i] == str[i + 1]) {
            i++;
            count++;
        }
        groups.push_back({str[i], count});
    }
    return groups;
}

bool isStretchy(const string& s, const string& word) {
    auto sGroups = getGroups(s);
    auto wordGroups = getGroups(word);
    if (sGroups.size() != wordGroups.size()) return false;

    for (int i = 0; i < sGroups.size(); i++) {
        if (sGroups[i].first != wordGroups[i].first) return false;
        if (sGroups[i].second < wordGroups[i].second || (sGroups[i].second < 3 && sGroups[i].second != wordGroups[i].second)) {
            return false;
        }
    }
    return true;
}
    int expressiveWords(string s, vector<string>& queries) {
         int count = 0;
    for (const string& word : queries) {
        if (isStretchy(s, word)) {
            count++;
        }
    }
    return count;
    }
};