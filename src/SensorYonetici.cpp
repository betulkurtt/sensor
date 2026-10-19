#include "SensorYonetici.h"

#include <fstream>
#include <utility>

namespace {
std::string csvAlani(const std::string& metin) {
    std::string sonuc = "\"";

    for (const char karakter : metin) {
        if (karakter == '\"') {
            sonuc += "\"\"";
        } else {
            sonuc += karakter;
        }
    }

    return sonuc + "\"";
}
}

void SensorYonetici::sensorEkle(std::unique_ptr<Sensor> sensor) {
    if (sensor) {
        sensorler_.push_back(std::move(sensor));
    }
}

void SensorYonetici::tumOlcumleriAl() {
    for (const auto& sensor : sensorler_) {
        olcumler_.push_back(sensor->olcumAl());
    }
}

const std::vector<Olcum>& SensorYonetici::olcumler() const {
    return olcumler_;
}

OlcumDurumu SensorYonetici::siniflandir(const Olcum& olcum) const {
    if (olcum.sensorTuru == "Sicaklik") {
        if (olcum.deger < 15.0 || olcum.deger > 32.0) {
            return OlcumDurumu::Kritik;
        }
        if (olcum.deger < 18.0 || olcum.deger > 28.0) {
            return OlcumDurumu::Uyari;
        }
        return OlcumDurumu::Normal;
    }

    if (olcum.sensorTuru == "Nem") {
        if (olcum.deger < 20.0 || olcum.deger > 70.0) {
            return OlcumDurumu::Kritik;
        }
        if (olcum.deger < 30.0 || olcum.deger > 60.0) {
            return OlcumDurumu::Uyari;
        }
        return OlcumDurumu::Normal;
    }

    if (olcum.sensorTuru == "Hareket") {
        return olcum.deger > 0.0 ? OlcumDurumu::Uyari : OlcumDurumu::Normal;
    }

    return OlcumDurumu::Normal;
}

bool SensorYonetici::olcumleriCsvKaydet(const std::string& dosyaYolu) const {
    std::ofstream dosya(dosyaYolu);
    if (!dosya) {
        return false;
    }

    dosya << "Sensor ID,Sensor Turu,Deger,Birim,Zaman,Durum\n";
    for (const Olcum& olcum : olcumler_) {
        dosya << csvAlani(olcum.sensorId) << ','
              << csvAlani(olcum.sensorTuru) << ','
              << olcum.deger << ','
              << csvAlani(olcum.birim) << ','
              << csvAlani(olcum.zaman) << ','
              << csvAlani(durumMetni(siniflandir(olcum))) << '\n';
    }

    return static_cast<bool>(dosya);
}
