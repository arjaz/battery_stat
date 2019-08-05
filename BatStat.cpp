#include "BatStat.h"

#include <filesystem>
#include <string>
#include <fstream>

BatStat::BatStat() = default;
BatStat::~BatStat() = default;

int BatStat::get_int_from_file(std::filesystem::path path) {
    std::ifstream file(path);
    if (!file) {
        return -1;
    }
    int result;
    file >> result;
    file.close();
    return result;
}

std::string BatStat::get_str_from_file(std::filesystem::path path) {
    std::ifstream file(path);
    if (!file) {
        return "";
    }
    std::string result;
    std::getline(file, result);
    file.close();
    return result;
}

int BatStat::getCurrentCharge() {
    return get_int_from_file(dir / bat / "charge_now");
}

int BatStat::getMaxCharge() {
    return get_int_from_file(dir / bat / "charge_full");
}

double BatStat::getPercentage() {
    float charge_current = get_int_from_file(dir / bat / "charge_now");
    float charge_full = get_int_from_file(dir / bat / "charge_full");
    return charge_current / charge_full;
}

std::string BatStat::getStatus() {
    std::string result = get_str_from_file(dir / bat / "status");
    return result;
}

bool BatStat::setBattery(std::filesystem::path bat) {
    if (std::filesystem::exists(dir / bat)) {
        this->bat = bat;
        return true;
    }
    return false;
}
