#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        int n = words.size();

        while (i < n) {
            int j = i;
            int letters = 0;

            // Find maximum words that fit in one line
            while (j < n && letters + words[j].size() + (j - i) <= maxWidth) {
                letters += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            int spaces = maxWidth - letters;
            string line;

            // Last line or line with only one word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1)
                        line += " ";
                }

                // Add remaining spaces at the end
                while (line.size() < maxWidth) {
                    line += " ";
                }
            }
            else {
                int spaceEach = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        // Left gaps get extra spaces
                        int currentSpaces = spaceEach;

                        if (k - i < extraSpaces)
                            currentSpaces++;

                        line += string(currentSpaces, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};