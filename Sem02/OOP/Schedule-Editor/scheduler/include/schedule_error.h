#pragma once

#include "common.h"

namespace scheduler {
    class ScheduleError : public runtime_error {
    public:
        explicit ScheduleError(const string &message);

        explicit ScheduleError(const char *message);
    };
}