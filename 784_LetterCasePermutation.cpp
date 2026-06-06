#include <iostream>
#include <vector>
#include <string>
#include <cctype>

class Solution {
public:
    // Backtracking (DFS) approach:
    // Generate all permutations by toggling the case of each letter.
    // For each position, either keep the character as-is or (if it's a letter) flip its case and recurse.
    void backtrack(std::string current, int index, std::vector<std::string>& output) {
        // DFS: when we reach the end, record the permutation
        if (index == static_cast<int>(current.size())) {
            output.push_back(current);
            return;
        }

        char ch = current[index];
        if (!std::isalpha(static_cast<unsigned char>(ch))) {
            // no branching for non-letters
            backtrack(current, index + 1, output);
        } else {
            // branch 1: keep the character as-is
            backtrack(current, index + 1, output);

            // branch 2: flip the character's case and recurse
            if (std::islower(static_cast<unsigned char>(ch)))
                current[index] = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
            else
                current[index] = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));

            backtrack(current, index + 1, output);
        }
    }

    std::vector<std::string> letterCasePermutation(std::string s) {
        std::vector<std::string> output;
        backtrack(s, 0, output);
        return output;
    }

    // Iterative (BFS-like) approach:
    // Build permutations progressively; when encountering a letter, duplicate current list with both cases.
    std::vector<std::string> letterCasePermutation(const std::string& s) {
        std::vector<std::string> permutations = {""};
        for (char ch : s) {
            if (std::isalpha(static_cast<unsigned char>(ch))) {
                size_t current_size = permutations.size();
                char upper_char = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
                char lower_char = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
                for (size_t i = 0; i < current_size; ++i) {
                    std::string temp = permutations[i];
                    permutations[i].push_back(lower_char);
                    temp.push_back(upper_char);
                    permutations.push_back(std::move(temp));
                }
            } else {
                for (auto& str : permutations)
                    str.push_back(ch);
            }
        }
        return permutations;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> permutations = sol.letterCasePermutation("a1b2");
    for (const auto& s : permutations) {
        std::cout << s << '\n';
    }
    return 0;
}
