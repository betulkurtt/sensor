#include "Sensor.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <utility>

namespace {
std::string simdikiZaman() {
    const auto simdi = std::chrono::system_clock::now();
    const std::time_t zaman = std::chrono::system_clock::to_time_t(simdi);
    std::tm yerelZaman{};

#if defined(_WIN32) && defined(_MSC_VER)
    localtime_s(&yerelZaman, &zaman);
#else
    if (const std::tm* lokal = std::localtime(&zaman)) {
        yerelZaman = *lokal;
    }
#endif

    std::ostringstream sonuc;
    sonuc << std::put_time(&yerelZaman, "%Y-%m-%d %H:%M:%S");
    return sonuc.str();
}
}

Sensor::Sensor(std::string id, std::string konum)
    : id_(std::move(id)), konum_(std::move(konum)) {}

const std::string& Sensor::id() const {
    return id_;
}

const std::string& Sensor::konum() const {
    return konum_;
}

Olcum Sensor::olcumOlustur(double deger) const {
    return {id(), tur(), deger, birim(), simdikiZaman()};
}
