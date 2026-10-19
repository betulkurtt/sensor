#pragma once

#include <string>

enum class OlcumDurumu {
    Normal,
    Uyari,
    Kritik
};

inline std::string durumMetni(OlcumDurumu durum) {
    switch (durum) {
    case OlcumDurumu::Normal:
        return "Normal";
    case OlcumDurumu::Uyari:
        return "Uyari";
    case OlcumDurumu::Kritik:
        return "Kritik";
    }

    return "Bilinmiyor";
}
