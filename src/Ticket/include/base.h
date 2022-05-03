#ifndef TKB_H
#define TKB_H

#include"ticket_bundle.h"
#include<stdlib.h>

typedef struct BASE_T {
  ticket_bundle ** general_population;
  int available_space;
}base;

typedef struct B_ID_T {
  int * id_space;
  int * active_ids; // 1 - active; 0 - inactive
  int size;
}b_id;

base * init_base(void);
b_id * init_b_id(void);
void add_ticket_bundle(base * b, b_id * bid, int partition_qty);
void free_ticket_bundle(base * b, int id);
void free_b_id(b_id * tbid);
void free_base(base * b);

#endif
