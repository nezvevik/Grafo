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

#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "serialize_lock.h"


int main(int argc, char *argv[])
{

  /* Serialize execution of applications */

	void * parlcd_base = map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);


  /* Try to acquire lock the first */
  if (serialize_lock(1) <= 0) {
	printf("System is occupied\n");

	if (1) {
	  printf("Waitting\n");
	  /* Wait till application holding lock releases it or exits */
	  serialize_lock(0);
	}
  }
  
  /***************************************************/
  /*                      CODE                       */
  /***************************************************/
	fprintf(stdout, "Starting application.\n");

  *(volatile uint32_t*)(parlcd_base + PARLCD_REG_DATA_o) = 0x2c;
  
  for (int y = 0; y < 320; y++)
  {
	  for (int x = 0; x < 100; x++)
	  {
		 
		  *(volatile uint32_t*)(parlcd_base + PARLCD_REG_DATA_o) = 0xaaaa;
	  }
  }


  fprintf(stodut, "End.\n");

  /* Release the lock */
  serialize_unlock();

  return 0;
}
