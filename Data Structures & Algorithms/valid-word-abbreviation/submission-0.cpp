class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;  // pointer for word
        int j = 0;  // pointer for abbr

        while (i < word.size() && j < abbr.size()) {

            // If abbr[j] is a letter
            if (isalpha(abbr[j])) {

                // Letter must match
                if (word[i] != abbr[j]) {
                    return false;
                }

                i++;
                j++;
            }

            // If abbr[j] is a number
            else {

                // Leading zero is not allowed
                if (abbr[j] == '0') {
                    return false;
                }

                int num = 0;

                // Read the complete number
                while (j < abbr.size() && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }

                // Skip 'num' characters in word
                i += num;
            }
        }

        // Both strings should be completely processed
        return i == word.size() && j == abbr.size();
    }
};