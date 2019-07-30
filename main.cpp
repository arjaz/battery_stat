#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>

int get_int_from_file(std::filesystem::path path) {
    std::ifstream file(path);
    if (!file) {
        return -1;
    }
    int result = 0;
    file >> result;
    return result;
}

struct options {
    bool exit{false};
    bool percentage{true};
};

struct options get_options(std::vector<std::string> const &args) {
    options opt;
    for (auto const &i : args) {
        if (i == "-h")
            opt.exit = true;
        if (i == "-a")
            opt.percentage = false;
    }
    return opt;
}

int main(int argc, char *argv[]) {
    namespace fs = std::filesystem;
    std::vector<std::string> args(argv, argv+argc);
    options opt = get_options(args);

    if (opt.exit) {
        std::string help = ""
            "This application is intended to provide information about the user's battery."
            "Available options:\n"
            "\t-h\tdisplay this message and exit\n"
            "\t-a\tdisplay voltage instead of percentage\n";
        std::cout << help;
        return 0;
    }

    fs::path bat_dir = "/sys/class/power_supply/BAT0";

    int charge_current = get_int_from_file(bat_dir / "charge_now");
    int charge_full = get_int_from_file(bat_dir / "charge_full");

    if (opt.percentage) {
        std::cout << 100 * float(charge_current) / float(charge_full) << "%" << std::endl;
    } else {
        std::cout << charge_current << "/" << charge_full << std::endl;
    }

    return 0;
}
