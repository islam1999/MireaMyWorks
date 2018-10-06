#include "common.h"

namespace scheduler {
    ScheduleError::ScheduleError(const string &message) : runtime_error{message} {}

    ScheduleError::ScheduleError(const char *message) : runtime_error{message} {}
}