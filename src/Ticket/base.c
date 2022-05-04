/**
 * @file base.c
 * @brief This file contains the functions relating to the way tickets are
 * distributed by the base
 * @NOTE in this file I talk about partitions but as we only care about memory
 * as a scalar not a vector, its technically not a "partition"
 * @author Matthew C. Lindeman
 * @date May 03, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/base.h"

/**
 * This funciton initializes the base for the universe
 * @param available_space - the total base units for the base
 * @return              b - the base
 */
base * init_base(b_id * bid, int total_space) {
  base * b = calloc(1, sizeof(struct BASE_T *));
  b->bid = bid;
  b->general_population = NULL;
  b->available_space = total_space;
  b->total_space = total_space;
  return b;
}

/**
 * This function makes a new partition in the general population for the 
 * @param             b - the base to be added onto
 * @param partition_qty - the total quantity of the partition
 * @return
 */
void add_ticket_bundle(base * b, int partition_qty) {
  b->available_space -= partition_qty;
  if(b->general_population) {
    b->general_population = realloc(b->general_population, b->bid->size
        * sizeof(struct TICKET_BUNDLE_T *));
  } else {
    b->general_population = calloc(b->bid->size,
        sizeof(struct TICKET_BUNDLE_T *));
  }
   b->general_population[b->bid->size - 1]
     = calloc(partition_qty, sizeof(struct TICKET_BUNDLE_T));
  for(int i = 0; i < partition_qty; i++) {
     b->general_population[b->bid->size - 1]
       = add_ticket(b->general_population[b->bid->size - 1], init_ticket(1, i));
  }
}

/**
 * This function removes a ticket bundle with id id from the base
 * @param    b - the base
 * @param   id - the id of the ticket bundle to be removed
 * @return N/a
 */
void delete_ticket_bundle(base * b, int id) {
  int tb_index = find_ticket_bundle(b, id);
  if(tb_index == -1) {
    fprintf(stderr, "[FREE_TICKET_BUNDLE]: ID: `%d` not found. Exiting\n", id);
    exit(1);
  }
  left_shift_general_population(b, id);
  delete_last_member(b);
}

/**
 * This function shifts everything right of id to the left one and puts id at
 * the end
 * @param    b - the base
 * @param   id - the id from which to be shifted
 * @return N/a
 */
void left_shift_general_population(base * b, int id) {
  ticket_bundle * tmp;
  tmp = b->general_population[id];
  for(int i = id; i < b->bid->size - 1; i++) {
    b->general_population[i] = b->general_population[i + 1];
  }
  b->general_population[b->bid->size - 1] = tmp;
}

/**
 * This function deletes the last member of the general_population
 * @param    b - the base
 * @return N/a
 */
void delete_last_member(base * b) {
  free_ticket_bundle(b->general_population[b->bid->size - 1]);
  b->general_population[b->bid->size - 1] = NULL;
  b->bid->size--;
}

/**
 * This funciton finds a ticket with id id
 * @param   b - the base from which to look
 * @param  id - the id of the ticket the user wishes to find
 * @return -1 - not found
 *          i - the index of the ticket_bundle
 */
int find_ticket_bundle(base * b, int id) {
  for(int i = 0; i < b->bid->size; i++) {
    if(b->general_population[i]->id == id) {
      return i;
    }
  }
  return -1;
}

/**
 * This function frees a base struct
 * @param    b - the base
 * @return N/a
 */
void free_base(base * b) {
  if(b) {
    if(b->general_population) {
      for(int i = 0; i < b->bid->size; i++) {
        free_ticket_bundle(b->general_population[i]);
      }
      free(b->general_population);
    }
    free(b);
  }
}

/**
 * This function dumps the stats of the base struct
 * @param    b - the base struct
 * @return N/a
 */
void base_dump_stats(base * b) {
  printf("===============================\n");
  printf("\tGENERAL POPULATION STATS\n");
  printf("===============================\n");
  for(int i = 0; i < b->bid->size; i++) {
    ticket_bundle_dump_stats(b->general_population[i]);
  }
  printf("===============================\n");
  printf("\tBASE ID STATS\n");
  printf("===============================\n");
  b_id_dump_stats(b->bid);
  printf("===============================\n");

  printf("-------------------------------\n");
  printf("AVAILABLE SPACE: %d\n", b->available_space);
  printf("    TOTAL SPACE: %d\n", b->available_space);
  printf("-------------------------------\n");
}
