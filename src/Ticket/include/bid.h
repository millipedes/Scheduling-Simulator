#ifndef BID_H
#define BID_H

#include<stdlib.h>

typedef struct B_ID_T {
  int * id_space;
  int * active_ids; // 1 - active; 0 - inactive
  int current_id;
  int size;
}b_id;

b_id * init_b_id(void);
void free_b_id(b_id * tbid);

#endif
