#define _POSIX_C_SOURCE 200112L

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "draw_utils.h"
#include "font_types.h"

void pchar(union pixel** buffer, char c, unsigned x, unsigned y, union pixel color) {
  for (unsigned w = 0; w < font_rom8x16.maxwidth; w++) {
    for (unsigned h = 0; h < font_rom8x16.height; h++) {
      if ((font_rom8x16.bits[(c - font_rom8x16.firstchar) * font_rom8x16.height + h] & (1<<(16-w))))
        buffer[x + w][y + h] = color;
    }
  }
}

void pstring(union pixel** buffer, char* word, unsigned x, unsigned y, union pixel color) {
	for (int i = 0; word[i] != '\0'; i++) {
		pchar(buffer, word[i], x + i * font_rom8x16.maxwidth, y, color);
	}
}
