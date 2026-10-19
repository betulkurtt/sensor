# Sensör

C++17 tabanlı, nesne yönelimli çoklu sensör veri yönetim sistemi.

## Özellikler

- Soyut `Sensor` sınıfı ve kalıtım ile sıcaklık, nem ve hareket sensörlerini modeller.
- Polimorfizm ve `std::unique_ptr` kullanarak güvenli dinamik bellek yönetimi sağlar.
- Sensörleri ve ölçüm geçmişini STL koleksiyonlarıyla yönetir.
- Eşik değerlerine göre ölçümleri `Normal`, `Uyari` ve `Kritik` olarak sınıflandırır.
- Ölçüm sonuçlarını CSV formatında dışa aktarır.
- CMake yapılandırması ve başlangıç kullanım bilgilerini içeren README ile derlemeye hazırdır.

## Proje yapısı

- `src/Sensor.h` ve `src/Sensor.cpp`: Soyut sensör temel sınıfı
- `src/SicaklikSensoru.*`: Sıcaklık sensörü
- `src/NemSensoru.*`: Nem sensörü
- `src/HareketSensoru.*`: Hareket sensörü
- `src/SensorYonetici.*`: Sensör ve ölçüm geçmişi yönetimi
- `src/main.cpp`: Örnek uygulama giriş noktası

## Derleme ve çalıştırma

### CMake ile

```powershell
cmake -S . -B build
cmake --build build --config Release
.\build\Release\sensor_yonetimi.exe
```

### G++ ile

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic .\src\*.cpp -o .\sensor_yonetimi.exe
.\sensor_yonetimi.exe
```

Program çalıştırıldığında ölçüm raporunu terminale yazdırır ve sonuçları
`olcumler.csv` dosyasına kaydeder.

## Başlangıç sınıflandırma eşikleri

| Sensör | Normal | Uyari | Kritik |
| --- | --- | --- | --- |
| Sıcaklık | 18–28 °C | 15–18 veya 28–32 °C | 15 °C altı veya 32 °C üstü |
| Nem | %30–60 | %20–30 veya %60–70 | %20 altı veya %70 üstü |
| Hareket | Algılanmadı | Algılandı | — |
