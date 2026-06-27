class Solution {
    public:
        vector<string> findWords(vector<string>& words) {
            vector<string> res;
            int row[26] = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};

            for (const string& word : words) {
                int currRow = row[tolower(word[0]) - 'a'];
                bool isValid = true;
                for (char c : word) {
                    if (row[tolower(c) - 'a'] != currRow) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    res.push_back(word);
                }
            }
            return res;
        }
};