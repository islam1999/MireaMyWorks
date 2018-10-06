#include <common.h>

namespace scheduler {
    void string_ltrim_ref(string &s) {
        s.erase(s.begin(), find_if(s.begin(), s.end(), not1(std::ptr_fun<int, int>(::isspace))));
    }

    void string_rtrim_ref(string &s) {
        s.erase(find_if(s.rbegin(), s.rend(), not1(std::ptr_fun<int, int>(::isspace))).base(), s.end());
    }

    void string_trim_ref(string &s) {
        string_ltrim_ref(s);
        string_rtrim_ref(s);
    }

    string string_ltrim(string s) {
        string_ltrim_ref(s);
        return s;
    }

    string string_rtrim(string s) {
        string_rtrim_ref(s);
        return s;
    }

    string string_trim(string s) {
        string_trim_ref(s);
        return s;
    }

    vector<string> string_split(const string &input, const string &regex) {
        std::regex re(regex);
        std::sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;
        return {first, last};
    }

    string string_join(vector<string> &strings, const string &connector) {
        string result;
        for (size_t i = 0; i < strings.size(); ++i) {
            if (i != 0)
                result += connector;
            result += strings[i];
        }
        return result;
    }
}