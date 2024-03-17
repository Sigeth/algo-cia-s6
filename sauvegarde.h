#ifndef ALGO_CIA_S6_SAUVEGARDE_H
#define ALGO_CIA_S6_SAUVEGARDE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "types.h"

RULES* readRules();
int saveRules(RULES* listRules);

#endif
