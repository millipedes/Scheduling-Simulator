/**
 * @file thread.h
 * @brief this file contains the funciton definitions for thread.c
 * @author Matthew C. Lindeman
 * @date May  04, 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef THRE_H
#define THRE_H

#include<stdlib.h>

typedef struct THREAD_T {
  int work_qty; // Work ovet time as we deal in quantums
}thread;

thread * init_thread(int work_qty);
void free_thread(thread * t);

#endif
