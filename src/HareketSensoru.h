#pragma once

#include "Sensor.h"

class HareketSensoru final : public Sensor {
public:
    HareketSensoru(const std::string& id, const std::string& konum, bool hareketAlgilandi);

    std::string tur() const override;
    std::string birim() const override;
    Olcum olcumAl() const override;

private:
    bool hareketAlgilandi_;
};
