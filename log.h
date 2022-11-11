#ifndef _LOG_H_LTY_
#define _LOG_H_LTY_
#include<stdio.h>
#define L_INFO(fmt, ...)  printf("[INFO ][%s %s] [%s] [%s:%d] "fmt"\n", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define L_ERROR(fmt, ...) printf("[ERROR][%s %s] [%s] [%s:%d] "fmt"\n", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define L_WARN(fmt, ...)  printf("[WARN ][%s %s] [%s] [%s:%d] "fmt"\n", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#endif
