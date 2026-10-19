#include "HareketSensoru.h"
#include "NemSensoru.h"
#include "SensorYonetici.h"
#include "SicaklikSensoru.h"

#include <iostream>
#include <memory>
#include <string>

int main() {
    SensorYonetici yonetici;
    yonetici.sensorEkle(std::make_unique<SicaklikSensoru>("SIC-01", "Sunucu Odasi", 27.4));
    yonetici.sensorEkle(std::make_unique<NemSensoru>("NEM-01", "Depo", 61.2));
    yonetici.sensorEkle(std::make_unique<HareketSensoru>("HAR-01", "Ana Giris", true));
    yonetici.tumOlcumleriAl();

    std::cout << "--- Sensor Olcum Raporu ---\n";
    for (const Olcum& olcum : yonetici.olcumler()) {
        std::cout << '[' << olcum.zaman << "] "
                  << olcum.sensorId << " (" << olcum.sensorTuru << "): "
                  << olcum.deger << ' ' << olcum.birim
                  << " | Durum: " << durumMetni(yonetici.siniflandir(olcum)) << '\n';
    }

    const std::string dosyaAdi = "olcumler.csv";
    if (yonetici.olcumleriCsvKaydet(dosyaAdi)) {
        std::cout << "\nOlcumler '" << dosyaAdi << "' dosyasina kaydedildi.\n";
    } else {
        std::cerr << "\nHata: CSV dosyasi olusturulamadi.\n";
        return 1;
    }

    return 0;
}
