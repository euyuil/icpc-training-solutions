class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {

        vector<string> lines;

        for (int i = 0, j; i < words.size(); i = j) {

            // calculate words range [i, j).

            int chars_remain = L - words[i].size();

            for (j = i + 1; j < words.size(); ++j) {
                int chars_needed = words[j].size() + 1;
                if (chars_needed > chars_remain) break;
                chars_remain -= chars_needed;
            }

            // calculate spaces.

            int space_size = 1, extra_spaces = 0, words_length = 0;

            for (int k = i; k < j; ++k)
                words_length += words[k].size();

            int spaces = L - words_length;

            // only 1 word in this line or last line.
            if (j - i == 1 || j == words.size()) {
                // using left justification.
            } else { // more than 1 word in this line
                space_size = spaces / (j - i - 1);
                extra_spaces = spaces % (j - i - 1);
            }

            // now we should add [i, j) to the line.

            int pos = 0;
            string line(L, ' ');

            for ( ; pos < words[i].size(); ++pos)
                line[pos] = words[i][pos]; // fill first (ith) word

            for (int k = i + 1; k < j; ++k) { // fill the rest words
                pos += space_size + (k - i <= extra_spaces ? 1 : 0);
                for (int l = 0; l < words[k].size(); ++pos, ++l)
                    line[pos] = words[k][l];
            }

            // push line

            lines.push_back(line);
        }

        return lines;
    }
};
