#define _POSIX_C_SOURCE 200112L

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#include "display_utils.h"
#include "draw_utils.h"

union pixel** allocate_buffer() {
	union pixel** buffer = (union pixel**)malloc(DISPLAY_SIZE_X * sizeof(uint16_t*));
    
	return NULL;
}
