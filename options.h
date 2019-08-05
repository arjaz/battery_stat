#ifndef OPTIONS_H
#define OPTIONS_H

#include <vector>
#include <string_view>

struct options {
    bool help{false};
    bool percentage{false};
    bool units{false};
    bool status{false};
};

struct options get_options(std::vector<std::string_view> const &args);

#endif

