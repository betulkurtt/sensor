#include "HareketSensoru.h"

HareketSensoru::HareketSensoru(const std::string& id, const std::string& konum, bool hareketAlgilandi)
    : Sensor(id, konum), hareketAlgilandi_(hareketAlgilandi) {}

std::string HareketSensoru::tur() const {
    return "Hareket";
}

std::string HareketSensoru::birim() const {
    return "durum";
}

Olcum HareketSensoru::olcumAl() const {
    return olcumOlustur(hareketAlgilandi_ ? 1.0 : 0.0);
}
