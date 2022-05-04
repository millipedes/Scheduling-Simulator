#include"include/bid.h"

/**
 * This function initializes a base id structure that is used to partition the
 * general population
 * @return bid - the base id structure
 */
b_id * init_b_id(void) {
  b_id * bid = calloc(1, sizeof(struct B_ID_T));
  bid->id_space = NULL;
  bid->active_ids = NULL;
  bid->current_id = 0;
  bid->size = 0;
  return bid;
}

void free_b_id(b_id * tbid) {
}
