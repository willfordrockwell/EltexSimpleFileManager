#ifndef __FILE_MANAGER_H__
#define __FILE_MANAGER_H__

#include <ncurses.h>
#include <malloc.h>

#include "graph/graph.h"

#define CHANGE_INTS(Current, First, Second) ((Current == &First) ? &Second : &First)

#define CHANGE_POINTERS(Current, First, Second) ((Current == First) ? Second : First)

#endif // !__FILE_MANAGER_H__