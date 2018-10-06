#include "common.h"

namespace scheduler {
    XlsxFile::XlsxFile(const string &filename) {
        load_new_file(filename);
    }

    XlsxFile::XlsxFile(const scheduler::XlsxFile &file) {
        load_new_file(file._filename);
    }

    XlsxFile::~XlsxFile() {
        if (_file_was_changed && _file_was_saved) {
            write();
        }

        delete _document;
    }

    schedule_index_t XlsxFile::get_max_row_index() const {
        return _max_row;
    }

    schedule_index_t XlsxFile::get_max_column_index() const {
        return _max_column;
    }

    const vector<vector<XlsxFile::XlsxCell>> &XlsxFile::get_rows() const {
        return _xlsx_info;
    }

    const vector<XlsxFile::XlsxCell> &XlsxFile::get_row(schedule_index_t index) const {
        _check_indices(index, 0);

        return _xlsx_info[index];
    }

    const string &XlsxFile::get_cell(schedule_index_t row, schedule_index_t column) const {
        _check_indices(row, column);

        return _xlsx_info[row][column].value;
    }

    void XlsxFile::set_cell(schedule_index_t row, schedule_index_t column, const string &value) {
        _check_indices(row, column);

        _file_was_changed = true;
        _file_was_saved = false;

        _xlsx_info[row][column].value = value;
        _xlsx_info[row][column].__was_changed = true;
    }

    const string &XlsxFile::get_file_name() const {
        return _filename;
    }

    void XlsxFile::set_file_name(const string &new_filename) {
        if (new_filename.empty()) {
            throw ScheduleError{"file can not have empty name"};
        }

        _filename = new_filename;
    }

    void XlsxFile::load_new_file(const string &filename) {
        _filename = filename;

        _document = new Document(filename.c_str());

        _xlsx_info.clear();
        _load_xlsx_into_info();
    }

    void XlsxFile::write_as(const string &new_filename) {
        set_file_name(new_filename);
        write();
    }

    void XlsxFile::write() {
        for (schedule_index_t row = 1; row < _max_row + 1; row++) {
            for (schedule_index_t column = 1; column < _max_column + 1; column++) {
                if (_xlsx_info[row - 1][column - 1].__was_changed) {
                    _document->write(row, column, QString(_xlsx_info.at(row - 1).at(column - 1).value.c_str()));
                }
            }
        }

        _document->saveAs(QString(_filename.c_str()));

        _file_was_changed = false;
        _file_was_saved = true;
    }

    void XlsxFile::save() {
        _file_was_saved = true;
    }

    void XlsxFile::discard_saving() {
        _file_was_saved = false;
    }

    void XlsxFile::_load_xlsx_into_info() {
        _max_row = _document->dimension().lastRow();
        _max_column = _document->dimension().lastColumn();

        for (schedule_index_t row = 1; row <= _max_row; row++) {
            vector<XlsxCell> row_info;
            for (schedule_index_t column = 1; column <= _max_column; column++) {
                Cell *c = _document->cellAt(row, column);
                if (c) {
                    row_info.emplace_back(XlsxCell{c->value().toString().toStdString()});
                } else {
                    row_info.emplace_back(XlsxCell{});
                }
            }
            _xlsx_info.push_back(row_info);
        }
    }

    void XlsxFile::_check_indices(schedule_index_t row, schedule_index_t column) const {
        if (row >= _max_row)
            throw ScheduleError{"row " + to_string(row) + " is not accessible"};

        if (column >= _max_column)
            throw ScheduleError{"column " + to_string(column) + " is not accessible"};
    }
}
