#include<stdio.h>
#include"Ticket/include/base.h"
#include"Ticket/include/ticket_bundle.h"
#include"Ticket/include/bid.h"

#define TMP_LEN 20

int main(void) {
  b_id * bid =  init_b_id();
  base * b = init_base(bid, TMP_LEN);
  add_ticket_bundle(b, 2);
  base_dump_stats(b);
  return 0;
}
