#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <unordered_map>
#include <algorithm>
#include <cstdint>

#include <xlsxdocument.h>

using namespace std;
using namespace QXlsx;

namespace scheduler {
    class Lesson;

    using schedule_index_t = uint64_t;
    using day_template = unordered_map<int, Lesson>;
    using week_template = unordered_map<int, day_template>;
    using parity_week_template = unordered_map<int, week_template>;

    void string_ltrim_ref(string &s);

    void string_rtrim_ref(string &s);

    void string_trim_ref(string &s);

    string string_ltrim(string s);

    string string_rtrim(string s);

    string string_trim(string s);

    vector<string> string_split(const string &input, const string &regex);

    string string_join(vector<string> &strings, const string &connector);
}

#include "schedule_error.h"
#include "lesson.h"
#include "xlsx_file.h"
#include "group_schedule.h"
#include "scheduler.h"