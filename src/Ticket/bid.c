/**
 * @file bid.c
 * @brief this file contains the functions related to the base id structure.
 * This is essentially an analogous partition (NB: without directional
 * restriction, i.e. there is no fragmentation as that would imply direction)
 * @author Matthew C. Lindeman
 * @date May 03, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/bid.h"

/**
 * This function initializes a base id structure that is used to partition the
 * general population
 * @return bid - the base id structure
 */
b_id * init_b_id(void) {
  b_id * bid = calloc(1, sizeof(struct B_ID_T));
  bid->active_ids = NULL;
  bid->current_id = 0;
  bid->size = 0;
  return bid;
}

/**
 * This function performs the operations required to generate an id
 * @param         bid - the base id to generate the
 * @return current_id - the generated id
 */
int generate_id(b_id * bid) {
  bid->size++;
  bid->current_id++;
  if(bid->active_ids) {
    bid->active_ids = realloc(bid->active_ids, bid->size * sizeof(int));
  } else {
    bid->active_ids = calloc(bid->size, sizeof(int));
  }
  bid->active_ids[bid->size - 1] = bid->current_id;
  return bid->current_id;
}

/**
 * This function frees the bid struct
 * @param bid - the bid struct
 * @return N/a
 */
void free_b_id(b_id * bid) {
  if(bid) {
    if(bid->active_ids) {
      free(bid->active_ids);
    }
    free(bid);
  }
}
