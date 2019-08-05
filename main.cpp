#include <iostream>
#include <vector>
#include <string_view>

#include "BatStat.h"
#include "options.h"

int main(int argc, char *argv[]) {
    namespace fs = std::filesystem;
    std::vector<std::string_view> args(argv, argv+argc);
    options opt = get_options(args);

    if (opt.help) {
        std::string_view help = ""
            "This application is intended to provide information about the user's battery.\n"
            "\n"
            "Available options:\n"
            "\t-h\tdisplay this message and exit\n"
            "\t-p\tdisplay percentage\n"
            "\t-u\tdisplay units\n"
            "\t-s\tdisplay status of battery\n";
        std::cout << help;
        return 0;
    }

    BatStat battery_stat;

    if (opt.status) {
        std::cout << battery_stat.getStatus() << std::endl;
    }
    if (opt.percentage) {
        std::cout << 100 * battery_stat.getPercentage() << "%" << std::endl;
    }
    if (opt.units) {
        std::cout << battery_stat.getCurrentCharge() << "/" << battery_stat.getMaxCharge() << std::endl;
    }

    return 0;
}
