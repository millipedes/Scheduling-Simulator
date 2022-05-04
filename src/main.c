/**
 * @file main.c
 * @brief This file contains the entry point for the project
 * @author Matthew C. Lindeman
 * @date May 03, 2022
 * @bug None known
 * @todo Nothing
 */
#include<stdio.h>
#include"Ticket/include/base.h"
#include"Ticket/include/ticket_bundle.h"
#include"Ticket/include/bid.h"

#define TMP_LEN 20

int main(void) {

  base * b = init_base(TMP_LEN);
  add_ticket_bundle(b, 2);
  base_dump_stats(b);

  free_base(b);
  return 0;
}
