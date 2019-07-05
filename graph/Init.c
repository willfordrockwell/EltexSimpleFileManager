#include "graph.h"

void Init(struct Tab *First, struct Tab *Second, int Rows, int Cols)
{
    int Start_Y = 0;
    int Start_X_First = 0;
    int Start_X_Second = (Cols / 2);
    initscr();
    #ifndef DEBUG
        noecho();
    #endif
    cbreak();
    signal(SIGWINCH, Sig_Winch);
    keypad(stdscr, 1);

    start_color();
    #ifndef DEBUG
        curs_set(0);
    #endif
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    #ifndef DEBUG
        wattron(stdscr, A_BOLD);
        refresh();
    #endif // !DEBUG

    Init_Tab(First, Rows, Cols / 2, Start_Y, Start_X_First);
    Out_Window_Title(First->Tab, "First Tab");
    Init_Tab(Second, Rows, Cols / 2, Start_Y, Start_X_Second);
    Out_Window_Title(Second->Tab, "Second Tab");
}
