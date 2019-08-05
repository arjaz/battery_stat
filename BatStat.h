#ifndef BATSTAT_H
#define BATSTAT_H

#include <filesystem>
#include <string>

class BatStat {
private:
    int get_int_from_file(std::filesystem::path path);
    std::string get_str_from_file(std::filesystem::path path);

    std::filesystem::path dir{"/sys/class/power_supply"};
    std::filesystem::path bat{"BAT0"};

public:
    BatStat();
    virtual ~BatStat();

    int getCurrentCharge();
    int getMaxCharge();
    double getPercentage();
    std::string getStatus();
};

#endif /* BATSTAT_H */
