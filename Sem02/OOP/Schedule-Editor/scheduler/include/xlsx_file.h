#pragma once

#include "common.h"

namespace scheduler {
    class XlsxFile {
    public:
        struct XlsxCell {
            string value{};
            bool __was_changed = false;
        };

        explicit XlsxFile(const string &filename);

        XlsxFile(const XlsxFile &file);

        virtual ~XlsxFile();

        schedule_index_t get_max_row_index() const;

        schedule_index_t get_max_column_index() const;

        const vector<vector<XlsxCell>> &get_rows() const;

        const vector<XlsxCell> &get_row(uint64_t index) const;

        const string &get_cell(schedule_index_t row, schedule_index_t column) const;

        void set_cell(schedule_index_t row, schedule_index_t column, const string &value);

        const string &get_file_name() const;

        void set_file_name(const string &new_filename);

        void load_new_file(const string &filename);

        void write_as(const string &new_filename);

        void write();

        void save();

        void discard_saving();

    private:
        bool _file_was_changed = false;
        bool _file_was_saved = false;

        string _filename;
        Document *_document;

        vector<vector<XlsxCell>> _xlsx_info{};

        schedule_index_t _max_row{}, _max_column{};

        void _load_xlsx_into_info();

        void _check_indices(schedule_index_t row, schedule_index_t column) const;
    };
}
