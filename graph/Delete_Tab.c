#include "graph.h"

void Delete_Tab(struct Tab *Tab)
{
    delwin(Tab->Time);
    delwin(Tab->Size);
    delwin(Tab->Name);
    delwin(Tab->Tab);
}