#pragma once

#include "Sensor.h"

class NemSensoru final : public Sensor {
public:
    NemSensoru(const std::string& id, const std::string& konum, double ornekDeger);

    std::string tur() const override;
    std::string birim() const override;
    Olcum olcumAl() const override;

private:
    double ornekDeger_;
};
