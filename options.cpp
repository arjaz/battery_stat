#include "options.h"

#include <vector>
#include <string_view>
#include <algorithm>
#include <iterator>

struct options get_options(std::vector<std::string_view> const &args) {
    options opt;

    if (args.size() == 1) {
        opt.help = true;
        return opt;
    }

    if (std::find(args.begin(), args.end(), "-h") != args.end()) {
        opt.help = true;
    }
    if (std::find(args.begin(), args.end(), "-u") != args.end()) {
        opt.units = true;
    }
    if (std::find(args.begin(), args.end(), "-p") != args.end()) {
        opt.percentage = true;
    }
    if (std::find(args.begin(), args.end(), "-s") != args.end()) {
        opt.status = true;
    }
    auto ch_bat = std::find(args.begin(), args.end(), "-b");
    if (ch_bat != args.end()) {
        opt.battery = true;
        opt.battery_name = *(std::next(ch_bat));
    }
    return opt;
}

