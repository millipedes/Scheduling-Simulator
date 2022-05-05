/**
 * @file lottery.h
 * @brief This file contains the function definitions for lottery.c
 * @author Matthew C. Lindeman
 * @date May 05, 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef LOT_H
#define LOT_H

#include<stdlib.h>
#include<time.h>
#include"../../CPU/include/proc_list.h"
#include"../../CPU/include/thread.h"

void host_lottery(thread * t, proc_list * pl);

#endif
