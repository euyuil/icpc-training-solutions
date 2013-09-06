class Solution {
public:
    string simplifyPath(string path) {

        int out = 0;
        const char *begin = path.c_str(), *end;

        while (*begin) {

            while (*begin == '/') ++begin;
            for (end = begin; *end && *end != '/'; ++end);

            int n = end - begin;
            if (n == 0) break;
            if (n == 1 && *begin == '.') {
            } else if (n == 2 && *begin == '.' && *(begin + 1) == '.') {
                while (out > 0 && path[--out] != '/');
            } else {
                path[out++] = '/';
                for ( ; begin < end; ++begin)
                    path[out++] = *begin;
            }

            begin = end;
        }

        path.resize(out);

        if (path.size() == 0)
            path.resize(1, '/');

        return path;
    }
};
