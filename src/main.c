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
