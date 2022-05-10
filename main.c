/*******************************************************************
  Project main function template for MicroZed based MZ_APO board
  designed by Petr Porazil at PiKRON

  change_me.c      - main file

  include your name there and license for distribution.

  Remove next text: This line should not appear in submitted
  work and project name should be change to match real application.
  If this text is there I want 10 points subtracted from final
  evaluation.

 *******************************************************************/

#define _POSIX_C_SOURCE 200112L

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "font_types.h"
#include "draw_utils.h"
#include "draw_utils.c"
#include "display_utils.h"



int main(int argc, char *argv[])
{
	union pixel** buffer = (union pixel**)malloc(DISPLAY_SIZE_X * sizeof(union pixel*));
	for (int i = 0; i < DISPLAY_SIZE_X; i++) {
		buffer[i] = (union pixel*)malloc(DISPLAY_SIZE_Y * sizeof(union pixel));
		if (!buffer[i]){
			fprintf(stderr, "MEMORY ERROR.\n");
			return 101;
		}
	}
	
	
  volatile void *spiled_reg_base = map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
  volatile uint32_t *ledline = (spiled_reg_base + SPILED_REG_LED_LINE_o);
  volatile uint32_t *rgb1 = (spiled_reg_base + SPILED_REG_LED_RGB1_o);
  *ledline = 0x6600;
  *rgb1 = ((union led){ .r = 0xff, .g = 0xff, .b = 0xff}).data;

  for (unsigned x = 0; x < DISPLAY_SIZE_X; x++) {
          for (unsigned y = 0; y < DISPLAY_SIZE_Y; y++) {
			if (y < DISPLAY_SIZE_Y/2) {
                  buffer[x][y].data = 0xffff;			
			} else {
					buffer[x][y].data = 0xf1f0;
			}
		}
	}


  for (unsigned i = 0; i < 100; i++) {
          buffer[20][i + 20] = (union pixel){ .b = 0x1f };
          buffer[i + 20][20] = (union pixel){ .b = 0x1f };
          buffer[120][i + 20] = (union pixel){ .b = 0x1f };
          buffer[i + 20][120] = (union pixel){ .b = 0x1f };
  }

union pixel mycolor = {.data = 0xf100}; // red
	pstring(buffer, "HELLO WORLD", 300, 100, mycolor);


  unsigned char *parlcd_reg_base = map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
  parlcd_write_cmd(parlcd_reg_base, 0x2c);

  for (unsigned y = 0; y < DISPLAY_SIZE_Y; y++)
          for (unsigned x = 0; x < DISPLAY_SIZE_X; x++)
                  parlcd_write_data(parlcd_reg_base, buffer[x][y].data);
  return 0;
}
