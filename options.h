#ifndef OPTIONS_H
#define OPTIONS_H

#include <vector>
#include <string_view>

struct options {
    bool help{false};
    std::string_view const help_msg {
        "This application is intended to provide information about the user's battery.\n"
        "\n"
        "Available options:\n"
        "\t-h\tdisplay this message and exit\n"
        "\t-p\tdisplay percentage\n"
        "\t-u\tdisplay units\n"
        "\t-s\tdisplay status of battery\n"
    };
    bool percentage{false};
    bool units{false};
    bool status{false};
    bool battery{false};
    std::string_view battery_name{"BAT0"};
};

struct options get_options(std::vector<std::string_view> const &args);

#endif

