#include "SicaklikSensoru.h"

SicaklikSensoru::SicaklikSensoru(const std::string& id, const std::string& konum, double ornekDeger)
    : Sensor(id, konum), ornekDeger_(ornekDeger) {}

std::string SicaklikSensoru::tur() const {
    return "Sicaklik";
}

std::string SicaklikSensoru::birim() const {
    return "C";
}

Olcum SicaklikSensoru::olcumAl() const {
    return olcumOlustur(ornekDeger_);
}
