#pragma once

#include "common.h"

namespace scheduler {
    class GroupSchedule {
    public:
        GroupSchedule();

        explicit GroupSchedule(string group_name);

        virtual ~GroupSchedule() = default;

        static bool is_group_name_valid(const string &group_name);

        const string &get_group_name() const;

        void set_group_name(const string &group_name);

        const string &get_group_faculty() const;

        void set_group_faculty(const string &group_faculty);

        const string &get_group_magic_number() const;

        void set_group_magic_number(const string &group_magic_number);

        const Lesson &get_lesson(int parity, int day, int lesson_number) const;

        void set_lesson(int parity, int day, int lesson_number, const Lesson &lesson);

        void add_addition_message(const string &message, int day_number);

        string to_string() const;

        friend ostream &operator<<(ostream &os, const GroupSchedule &gs);

        Lesson &get_lesson_non_const_ref(int parity, int day, int lesson_number) const;

    private:
        const static regex _group_name_template;
        string _group_name;
        string _group_faculty;
        string _group_magic_number; // I don't know what this number means
        parity_week_template _group_schedule;

        void _create_group_schedule_template();

        void _check_parity_day_and_lesson(int parity, int day, int lesson) const;
    };
}
