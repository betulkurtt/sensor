#pragma once

#include "Olcum.h"
#include "OlcumDurumu.h"
#include "Sensor.h"

#include <memory>
#include <string>
#include <vector>

class SensorYonetici {
public:
    void sensorEkle(std::unique_ptr<Sensor> sensor);
    void tumOlcumleriAl();

    const std::vector<Olcum>& olcumler() const;
    OlcumDurumu siniflandir(const Olcum& olcum) const;
    bool olcumleriCsvKaydet(const std::string& dosyaYolu) const;

private:
    std::vector<std::unique_ptr<Sensor>> sensorler_;
    std::vector<Olcum> olcumler_;
};
