#ifndef DISPLAY_UTILS_H
#define DISPLAY_UTILS_H

#include <stdint.h>

#include "draw_utils.h"

#define DISPLAY_SIZE_X 480
#define DISPLAY_SIZE_Y 320

union pixel** allocate_buffer();

#endif  /*DISPLAY_UTILS_H*/
