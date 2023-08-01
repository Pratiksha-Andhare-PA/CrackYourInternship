#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_CHAR = 256;

// Function to preprocess the Bad Character Heuristic array
void badCharHeuristic(const string& pattern, vector<int>& badChar) {
    int m = pattern.length();

    for (int i = 0; i < MAX_CHAR; i++) {
        badChar[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        badChar[static_cast<int>(pattern[i])] = i;
    }
}

// Function implementing the Boyer-Moore algorithm
void boyerMooreSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> badChar(MAX_CHAR, -1);

    badCharHeuristic(pattern, badChar);

    int shift = 0;
    while (shift <= (n - m)) {
        int j = m - 1;

        // Keep reducing index j of the pattern while characters of the pattern
        // and text are matching at this shift
        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }
        /* If the pattern is present at current
        shift, then index j will become -1 after
        the above loop */
        
        if (j < 0) {
            cout << "Pattern found at index: " << shift << endl;
            /* Shift the pattern so that the next
            character in text aligns with the last
            occurrence of it in pattern.
            The condition s+m < n is necessary for
            the case when pattern occurs at the end
            of text */
            shift += (shift + m < n) ? m - badChar[static_cast<int>(text[shift + m])] : 1;
        } else {
           /* Shift the pattern so that the bad character
            in text aligns with the last occurrence of
            it in pattern. The max function is used to
            make sure that we get a positive shift.
            We may get a negative shift if the last
            occurrence of bad character in pattern
            is on the right side of the current
            character. */
            shift += max(1, j - badChar[static_cast<int>(text[shift + j])]);
        }
    }
}

int main() {
    string text = "AABAACAADAABAAABAA";
    string pattern = "AABA";

    boyerMooreSearch(text, pattern);

    return 0;
}
