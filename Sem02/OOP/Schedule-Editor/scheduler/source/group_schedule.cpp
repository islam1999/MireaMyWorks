#include "common.h"

namespace scheduler {
    const regex GroupSchedule::_group_name_template{
            R"([A-zА-яЁё]{4}-\d{2}-\d{2})"}; // disable notification about global variable => /* NOLINT */

    GroupSchedule::GroupSchedule() {
        _group_name = "";
        _create_group_schedule_template();
    }

    GroupSchedule::GroupSchedule(string group_name) : _group_name{move(group_name)} {
        _create_group_schedule_template();
    }

    bool GroupSchedule::is_group_name_valid(const string &group_name) {
        return regex_search(group_name, _group_name_template);
    }

    const string &GroupSchedule::get_group_name() const {
        return _group_name;
    }

    void GroupSchedule::set_group_name(const string &group_name) {
        if (!is_group_name_valid(group_name))
            throw ScheduleError{
                    "groupScheduleRef name '" + group_name + "' is wrong, template is 'LLLL-DD-DD'(L - letter, D - digit)"};

        _group_name = group_name;
    }

    const string &GroupSchedule::get_group_faculty() const {
        return _group_faculty;
    }

    void GroupSchedule::set_group_faculty(const string &group_faculty) {
        _group_faculty = group_faculty;
    }

    const string &GroupSchedule::get_group_magic_number() const {
        return _group_magic_number;
    }

    void GroupSchedule::set_group_magic_number(const string &group_magic_number) {
        _group_magic_number = group_magic_number;
    }

    const Lesson &GroupSchedule::get_lesson(int parity, int day, int lesson_number) const {
        _check_parity_day_and_lesson(parity, day, lesson_number);

        return _group_schedule.at(parity).at(day).at(lesson_number);
    }

    void GroupSchedule::set_lesson(int parity, int day, int lesson_number, const Lesson &lesson) {
        _check_parity_day_and_lesson(parity, day, lesson_number);

        _group_schedule.at(parity).at(day).at(lesson_number) = lesson;
    }

    void GroupSchedule::add_addition_message(const string &message, int day_number) {
        for (int lesson_number = 1; lesson_number < 7; lesson_number++) {
            for (int parity = 1; parity < 3; parity++) {
                _group_schedule.at(parity).at(day_number).at(lesson_number).add_addition(message);
            }
        }
    }

    // create json-like string representation of groupScheduleRef
    string GroupSchedule::to_string() const {
        string result = "GroupSchedule for '" + _group_name + "' on '" + _group_faculty + "' faculty with '" +
                        _group_magic_number + "' magic number: {\n\t";
        for (int parity = 1; parity < 3; parity++) {
            result += "\"" + std::to_string(parity) + "\": {\n\t\t";
            for (int day_number = 1; day_number < 7; day_number++) {
                result += "\"" + std::to_string(day_number) + "\": {\n\t\t\t";
                for (int lesson_number = 1; lesson_number < 7; lesson_number++) {
                    result += "\"" + std::to_string(lesson_number) + "\": {\n\t\t\t\t";
                    Lesson l = _group_schedule.at(parity).at(day_number).at(lesson_number);
                    result += l.to_string("\n\t\t\t\t");
                    result += "\n\t\t\t}" + string{lesson_number == 6 ? "" : ",\n\t\t\t"};
                }
                result += "\n\t\t}" + string{day_number == 6 ? "" : ",\n\t\t"};
            }
            result += "\n\t}" + string{parity == 2 ? "" : ",\n\t"};
        }
        result += "\n}\n";
        return result;
    }

    ostream &operator<<(ostream &os, const GroupSchedule &gs) {
        os << gs.to_string();
        return os;
    }

    void GroupSchedule::_create_group_schedule_template() {
        day_template dt;
        week_template wt;

        for (int i = 1; i < 7; i++) {
            pair<int, Lesson> tmp_pair(i, Lesson{});
            dt.emplace(tmp_pair);
        }
        for (int i = 1; i < 7; i++) {
            pair<int, day_template> tmp_pair(i, dt);
            wt.emplace(tmp_pair);
        }
        for (int i = 1; i < 3; i++) {
            pair<int, week_template> tmp_pair(i, wt);
            _group_schedule.emplace(tmp_pair);
        }
    }

    void GroupSchedule::_check_parity_day_and_lesson(int parity, int day, int lesson) const {
        if (parity < 1 || parity > 2)
            throw ScheduleError{"wrong parity: " + std::to_string(parity) + ", supported values are from 1 to 2"};

        if (day < 1 || day > 6)
            throw ScheduleError{"wrong day: " + std::to_string(day) + ", supported values are from 1 to 6"};

        if (lesson < 1 || lesson > 6)
            throw ScheduleError{
                    "wrong lesson number: " + std::to_string(lesson) + ", supported values are from 1 to 6"};
    }

    Lesson &GroupSchedule::get_lesson_non_const_ref(int parity, int day, int lesson_number) const {
        return const_cast<Lesson &>(get_lesson(parity, day, lesson_number));
    }
}