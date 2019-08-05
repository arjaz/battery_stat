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
        std::cout << opt.help_msg;
        return 0;
    }

    BatStat battery_stat;

    if (opt.battery) {
        if (battery_stat.setBattery(opt.battery_name)){
            std::cout << "Battery was changed to " << opt.battery_name << std::endl;
        } else {
            std::cerr << "Battery \"" << opt.battery_name << "\" could not be identified" << std::endl;
            return 1;
        }
    }
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
