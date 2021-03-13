/*
 * length.c
 *
 * Created: 13.03.2021
 * Author: Nicolas
 * Description: Fetches lenght of strings and ints
 */ 
#pragma once

#ifndef LENGTH_H_
#define LENGTH_H_

#if __cplusplus
extern "C" {
#endif

int get_int_len(int);
int get_str_len(char*);

#if __cplusplus
}
#endif

#endif