#pragma once

#include <cstdint>

struct Color {
    union {
        struct {
            uint8_t blue;
            uint8_t green;
            uint8_t red;
            uint8_t alpha;
        };
        uint8_t raw[4];
        uint32_t value;
    };

    Color()
     : value(0) { }

    Color(uint32_t value)
     : value(value) { }

    Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
     : blue(blue),
       green(green),
       red(red),
       alpha(alpha) { }

    Color(const Color& color)
     : value(color.value) { }

    Color& operator=(const Color& color) {
        if(this != &color) {
            value = color.value;
        }
        return *this;
    }
};
