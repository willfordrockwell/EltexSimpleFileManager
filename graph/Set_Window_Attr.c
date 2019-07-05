#include "graph.h"

void Set_Window_Attr(struct Tab *Tab, int File_Selection, int Is_Dir,
                     int Counter)
{
    if (Counter == File_Selection) {
            if (Is_Dir) {
                wattron(Tab->Name, A_REVERSE | A_BOLD);
                wattron(Tab->Size, A_REVERSE | A_BOLD);
                wattron(Tab->Time, A_REVERSE | A_BOLD);
            }
            else {
                wattron(Tab->Name, A_REVERSE);
                wattron(Tab->Size, A_REVERSE);
                wattron(Tab->Time, A_REVERSE);
            }
        }
        else {
            if (Is_Dir) {
                wattron(Tab->Name, A_BOLD);
                wattron(Tab->Size, A_BOLD);
                wattron(Tab->Time, A_BOLD);
            }
            else {
                wattron(Tab->Name, A_NORMAL);
                wattron(Tab->Size, A_NORMAL);
                wattron(Tab->Time, A_NORMAL);
            }
        }
}