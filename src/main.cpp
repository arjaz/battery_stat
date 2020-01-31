#include <iostream>

#include "BatStat.h"
#include "gitversion.h".h "
#include "options.h"

int main(int argc, char **argv) {
    options_t opt = get_options(argc, argv);

    if (opt.help || opt.empty) {
        std::cout << opt.help_msg;
        return 0;
    }
    if (opt.version) {
        std::cout << "Version:\t" << GIT_REVISION << std::endl;
        std::cout << "Build date:\t" << BUILD_TIMESTAMP << std::endl;
        return 0;
    }

    BatStat battery_stat;

    if (opt.battery != "BAT0") {
        if (battery_stat.setBattery(opt.battery)) {
            std::cout << "Battery was changed to " << opt.battery << std::endl;
        } else {
            std::cerr << "Battery \"" << opt.battery
                      << "\" could not be identified" << std::endl;
            return 1;
        }
    }
    if (opt.status) {
        std::cout << battery_stat.getStatus() << std::endl;
    }
    if (opt.percentage && !opt.long_percentage) {
        std::cout << int(100 * battery_stat.getPercentage()) << "%"
                  << std::endl;
    } else if (opt.long_percentage) {
        std::cout << 100 * battery_stat.getPercentage() << "%" << std::endl;
    }
    if (opt.units) {
        std::cout << battery_stat.getCurrentCharge() << "/"
                  << battery_stat.getMaxCharge() << std::endl;
    }

    return 0;
}
