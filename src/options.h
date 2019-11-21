#ifndef OPTIONS_H
#define OPTIONS_H

#include <string_view>

struct options_t {
    bool empty{true};
    bool help{false};
    bool version{false};
    static std::string_view const help_msg;
    bool percentage{false};
    bool long_percentage{false};
    bool units{false};
    bool status{false};
    std::string_view battery{"BAT0"};
};

struct options_t get_options(int argc, char **argv);

#endif

