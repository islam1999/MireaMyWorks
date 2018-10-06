#include "common.h"

namespace scheduler {
    Lesson::Lesson() : _subject_name{}, _lesson_type{}, _professor{}, _room{}, _additions{} {}


    Lesson::Lesson(string subject_name, string lesson_type, string professor, string room) :
            _subject_name{move(subject_name)}, _lesson_type{move(lesson_type)},
            _professor{move(professor)}, _room{move(room)}, _additions{} {}

    Lesson::Lesson(const Lesson &lesson) noexcept {
        _subject_name = lesson._subject_name;
        _lesson_type = lesson._lesson_type;
        _professor = lesson._professor;
        _room = lesson._room;
        _additions = lesson._additions;
    }

    Lesson::Lesson(Lesson &&lesson) noexcept {
        _subject_name = lesson._subject_name;
        _lesson_type = lesson._lesson_type;
        _professor = lesson._professor;
        _room = lesson._room;
        _additions = lesson._additions;
    }

    const string &Lesson::get_subject_name() const {
        return _subject_name;
    }

    void Lesson::set_subject_name(const string &subject_name) {
        _subject_name = subject_name;
    }

    const string &Lesson::get_lesson_type() const {
        return _lesson_type;
    }

    void Lesson::set_lesson_type(const string &lesson_type) {
        _lesson_type = lesson_type;
    }

    const string &Lesson::get_professor() const {
        return _professor;
    }

    void Lesson::set_professor(const string &professor) {
        _professor = professor;
    }

    const string &Lesson::get_room() const {
        return _room;
    }

    void Lesson::set_room(const string &room) {
        _room = room;
    }

    const vector<string> &Lesson::get_additions() const {
        return _additions;
    }

    void Lesson::set_additions(const vector<string> &additions) {
        _additions = additions;
    }

    void Lesson::add_addition(const string &addition) {
        _additions.push_back(const_cast<string &>(addition));
    }

    void Lesson::add_additions(const vector<string> &additions) {
        for (const string &addition: additions) {
            _additions.push_back(addition);
        }
    }

    string Lesson::to_string(const string &intends) const {

        string str_lesson = "Lesson: {" + intends +
                            "\tsubject: \"" + _subject_name + "\"," + intends +
                            "\ttype: \"" + _lesson_type + "\"," + intends +
                            "\tprofessor: \"" + _professor + "\"," + intends +
                            "\troom: \"" + _room + "\"," + intends +
                            "\tadditions: [";
        for (uint8_t i = 0; i < _additions.size(); i++) {
            str_lesson += intends + "\t\t\"" + _additions[i] + (i != _additions.size() - 1 ? "\"," : "\"");
        }
        str_lesson += intends + "\t]" + intends + "}";
        return str_lesson;
    }

    ostream &operator<<(ostream &os, const Lesson &lesson) {
        os << lesson.to_string();
        return os;
    }
}
