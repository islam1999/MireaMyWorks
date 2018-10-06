#include <gtest/gtest.h>

#include <common.h>

using namespace scheduler;

TEST(TESTS_COMMON, TEST_string_ltrim_ref) {
    string s = "    \t\ttext";
    string_ltrim_ref(s);
    ASSERT_EQ(s, "text") << "\"" << s << R"(" is not equal to "text")";
}

TEST(TESTS_COMMON, TEST_string_rtrim_ref) {
    string s = "text    \t\t";
    string_rtrim_ref(s);
    ASSERT_EQ(s, "text") << "\"" << s << R"(" is not equal to "text")";
}

TEST(TESTS_COMMON, TEST_string_trim_ref) {
    string s = "    \t\ttext    \t\t";
    string_trim_ref(s);
    ASSERT_EQ(s, "text") << "\"" << s << R"(" is not equal to "text")";
}

TEST(TESTS_COMMON, TEST_string_ltrim) {
    string s = "    \t\ttext";
    string trimed_string = string_ltrim(s);
    ASSERT_EQ(trimed_string, "text") << "\"" << s << R"(" is not equal to "text")";
}

TEST(TESTS_COMMON, TEST_string_rtrim) {
    string s = "text    \t\t";
    string trimed_string = string_rtrim(s);
    ASSERT_EQ(trimed_string, "text") << "\"" << s << R"(" is not equal to "text")";
}

TEST(TESTS_COMMON, TEST_string_trim) {
    string s = "    \t\ttext    \t\t";
    string trimed_string = string_trim(s);
    ASSERT_EQ(trimed_string, "text") << "\"" << s << R"(" is not equal to "text")";
}

TEST(TESTS_COMMON, TEST_string_split) {
    string s = "some text to split function";
    vector<string> v = string_split(s, R"(\s+)");
    ASSERT_EQ(v.size(), 5);
    ASSERT_EQ(v[0], "some");
    ASSERT_EQ(v[1], "text");
    ASSERT_EQ(v[2], "to");
    ASSERT_EQ(v[3], "split");
    ASSERT_EQ(v[4], "function");
}

TEST(TESTS_COMMON, TEST_string_join) {
    string s = "some text to split function";
    vector<string> v = string_split(s, R"(\s+)");
    string joined = string_join(v, " ");
    ASSERT_EQ(s, joined);
}
