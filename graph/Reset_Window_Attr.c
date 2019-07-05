#include "graph.h"

void Reset_Window_Attr(struct Tab *Tab, int File_Selection, int Is_Dir,
                       int Counter)
{
    if (Counter == File_Selection) {
            if (Is_Dir) {
                wattroff(Tab->Name, A_REVERSE | A_BOLD);
                wattroff(Tab->Size, A_REVERSE | A_BOLD);
                wattroff(Tab->Time, A_REVERSE | A_BOLD);
            }
            else {
                wattroff(Tab->Name, A_REVERSE);
                wattroff(Tab->Size, A_REVERSE);
                wattroff(Tab->Time, A_REVERSE);
            }
        }
        else {
            if (Is_Dir) {
                wattroff(Tab->Name, A_BOLD);
                wattroff(Tab->Size, A_BOLD);
                wattroff(Tab->Time, A_BOLD);
            }
            else {
                wattroff(Tab->Name, A_NORMAL);
                wattroff(Tab->Size, A_NORMAL);
                wattroff(Tab->Time, A_NORMAL);
            }
        }
}