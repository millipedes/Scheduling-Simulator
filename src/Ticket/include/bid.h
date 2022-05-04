/**
 * @file bid.c
 * @brief this file contains the function definitions for bid.c
 * @author Matthew C. Lindeman
 * @date May 03, 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef BID_H
#define BID_H

#include<stdlib.h>

typedef struct B_ID_T {
  int * active_ids; // indices
  int current_id;
  int size;
}b_id;

b_id * init_b_id(void);
int generate_id(b_id * bid);
void free_b_id(b_id * tbid);

#endif
