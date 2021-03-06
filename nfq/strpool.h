#pragma once

#include <stdbool.h>
#include <ctype.h>

//#define HASH_BLOOM 20
#define HASH_NONFATAL_OOM 1
#undef HASH_FUNCTION
#define HASH_FUNCTION HASH_BER
#include "uthash.h"

typedef struct strpool {
    char *str;           /* key */
    UT_hash_handle hh;         /* makes this structure hashable */
} strpool;

void StrPoolDestroy(strpool **p);
bool StrPoolAddStr(strpool **pp,const char *s);
bool StrPoolAddStrLen(strpool **pp,const char *s,size_t slen);
bool StrPoolCheckStr(strpool *p,const char *s);
