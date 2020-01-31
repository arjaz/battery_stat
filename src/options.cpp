#include "options.h"

#include <algorithm>
#include <getopt.h>
#include <iterator>
#include <string_view>
#include <vector>

std::string_view const options_t::help_msg =
    ""
    "This application is intended to provide information about the user's "
    "battery.\n"
    "\n"
    "Available options:\n"
    "\t--help\t\t-h\tdisplay this message and exit\n"
    "\t--version\t-v\tdisplay version and time stamp\n"
    "\t--percentage\t-p\tdisplay rounded percentage\n"
    "\t--long\t\t-l\tdisplay percentage\n"
    "\t--units\t\t-u\tdisplay units\n"
    "\t--status\t-s\tdisplay status of battery\n"
    "\t--battery\t-b\tspecify battery\n";

struct options_t get_options(int argc, char **argv) {
    options_t opt;

    while (true) {
        int option_index = 0;
        static option long_options[] = {{"help", no_argument, 0, 'h'},
                                        {"version", no_argument, 0, 'v'},
                                        {"percentage", no_argument, 0, 'p'},
                                        {"long", no_argument, 0, 'l'},
                                        {"status", no_argument, 0, 's'},
                                        {"units", no_argument, 0, 'u'},
                                        {"battery", required_argument, 0, 'b'},
                                        {0, 0, 0, 0}};

        int option = getopt_long(argc, argv, "hvplsub:", long_options, nullptr);
        if (option == -1)
            break;
        switch (option) {
        case 'h':
            opt.help = true;
            break;
        case 'v':
            opt.version = true;
            opt.empty = false;
            break;
        case 'p':
            opt.percentage = true;
            opt.empty = false;
            break;
        case 'l':
            opt.long_percentage = true;
            opt.empty = false;
            break;
        case 's':
            opt.status = true;
            opt.empty = false;
            break;
        case 'u':
            opt.units = true;
            opt.empty = false;
            break;
        case 'b':
            opt.battery = optarg;
            opt.empty = false;
            break;
        default:
            break;
        }
    }

    return opt;
}
