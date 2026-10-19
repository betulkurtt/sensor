#include "NemSensoru.h"

NemSensoru::NemSensoru(const std::string& id, const std::string& konum, double ornekDeger)
    : Sensor(id, konum), ornekDeger_(ornekDeger) {}

std::string NemSensoru::tur() const {
    return "Nem";
}

std::string NemSensoru::birim() const {
    return "%";
}

Olcum NemSensoru::olcumAl() const {
    return olcumOlustur(ornekDeger_);
}
