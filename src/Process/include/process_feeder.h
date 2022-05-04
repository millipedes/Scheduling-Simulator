/**
 * @file process_feeder.h
 * @brief This file contains the function definitions for process_feeder.c
 * @author Matthew C. Lindeman
 * @date May 04, 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef PROCF_H
#define PROCF_H

#include<stdio.h>
#include<stdlib.h>
#include"process.h"
#include"process_type.h"
#include"../../Ticket/include/base.h"

process * generate_process(base * base, process_type type, int work_qty);

#endif
