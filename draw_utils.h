#ifndef DRAW_UTILS_H
#define DRAW_UTILS_H

#include <stdint.h>

union led {
        struct {
                uint8_t b,g,r;
        };
        uint32_t data;
};
union pixel {
        struct {
                unsigned b : 5;
                unsigned g : 6;
                unsigned r : 5;
        };
        uint16_t data;
};

void pchar(union pixel** buffer, char c, unsigned x, unsigned y, union pixel color);
void pstring(union pixel** buffer, char* s, unsigned x, unsigned y, union pixel color);

#endif  /*DRAW_UTILS_H*/
