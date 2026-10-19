#pragma once

#include "Olcum.h"

#include <string>

class Sensor {
public:
    Sensor(std::string id, std::string konum);
    virtual ~Sensor() = default;

    const std::string& id() const;
    const std::string& konum() const;

    virtual std::string tur() const = 0;
    virtual std::string birim() const = 0;
    virtual Olcum olcumAl() const = 0;

protected:
    Olcum olcumOlustur(double deger) const;

private:
    std::string id_;
    std::string konum_;
};
