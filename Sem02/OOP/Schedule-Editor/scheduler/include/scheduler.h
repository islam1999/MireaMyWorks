#pragma once

#include "common.h"

namespace scheduler {
    class Scheduler {
    public:
        Scheduler();

        explicit Scheduler(const string &file_name);

        bool is_group_in_schedule(const string &group_name) const;

        const string &get_schedule_filename() const;

        void set_schedule_filename(const string &filename);

        void open_new_schedule(const string &filename);

        void create_new_empty_schedule(const string &filename);

        const vector<GroupSchedule> &get_groups() const;

        const GroupSchedule &get_group(const string &group_name) const;

        void add_group(const GroupSchedule &gs);

        void remove_group(const string &group_name);

        const string &get_cource_metainfo() const;

        void set_cource_metainfo(const string &metainfo_string);

        const string &get_confirmation_metainfo() const;

        void set_confirmation_metainfo(const string &metainfo_string);

        const pair<string, string> get_UMD_head_metainfo() const;

        void set_UMD_head_metainfo(const pair<string, string> &metainfo);

        const pair<string, string> get_headmaster_metainfo() const;

        void set_headmaster_metainfo(const pair<string, string> &metainfo);

        void save_schedule();

        void save_schedule_as(const string &filename);

        string to_string() const;

        friend ostream &operator<<(ostream &os, const Scheduler &scheduler);

        vector<GroupSchedule> &get_groups_non_const_ref() const;

        GroupSchedule &get_group_non_const_ref(const string &group_name) const;

    private:
        const static string _default_schedule_template_filename;
        const static string _default_schedule_filename;
        const static uint8_t _max_groups_count;

        XlsxFile _schedule;
        schedule_index_t _schedule_start_row, _schedule_start_col;
        vector<GroupSchedule> _groups{};

        string _schedule_date_and_course_metainfo;
        string _confirmation_metainfo;
        pair<string, string> _UMD_head_metainfo;
        pair<string, string> _headmaster_metainfo;

        schedule_index_t _get_group_name_row() const;

        void _fill_schedule_start_position();

        void _clear_attributes();

        int _get_group_index(const string &group_name) const;

        bool _check_for_free_day(pair<schedule_index_t, schedule_index_t> start_position) const;

        Lesson _fill_lesson(pair<schedule_index_t, schedule_index_t> start_position) const;

        void _parse_metainfo_for_group(GroupSchedule &gs, pair<schedule_index_t, schedule_index_t> start_position);

        void _parse_schedule_for_group(GroupSchedule &gs, pair<schedule_index_t, schedule_index_t> start_position);

        void _parse_schedule_metainfo();

        void _parse_schedule();

        void _load_schedule_metainfo_into_file();

        void _load_single_group_into_file(GroupSchedule &gs, schedule_index_t group_row,
                                          schedule_index_t group_start_position);

        void _load_groups_into_file();
    };
}
