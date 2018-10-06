#pragma once

#include "common.h"

using namespace std;

namespace scheduler {
    class Lesson {
    public:
        Lesson();

        Lesson(string subject_name, string lesson_type, string professor, string room);

        Lesson(const Lesson &lesson) noexcept;

        Lesson(Lesson &&lesson) noexcept;

        virtual ~Lesson() = default;

        Lesson &operator=(const Lesson &lesson) = default;

        Lesson &operator=(Lesson &&lesson) = default;

        const string &get_subject_name() const;

        void set_subject_name(const string &subject_name);

        const string &get_lesson_type() const;

        void set_lesson_type(const string &lesson_type);

        const string &get_professor() const;

        void set_professor(const string &professor);

        const string &get_room() const;

        void set_room(const string &room);

        const vector<string> &get_additions() const;

        void set_additions(const vector<string> &additions);

        void add_addition(const string &addition);

        void add_additions(const vector<string> &additions);

        string to_string(const string &intends = "\n\t") const;

        friend ostream &operator<<(ostream &os, const Lesson &lesson);

    private:
        string _subject_name;
        string _lesson_type;
        string _professor;
        string _room;
        vector<string> _additions;
    };
}
