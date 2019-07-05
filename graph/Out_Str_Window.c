#include "graph.h"

void Out_Str_Window(WINDOW *Wnd, int Start_Y, int Start_X, char *Input, int Length)
{
    for (int i = 0; i < Length; i++) {
        mvwaddch(Wnd, Start_Y, Start_X++, (*Input));
        Input++;
    }
    #ifndef DEBUG
        wrefresh(Wnd);
    #endif // !DEBUG
}