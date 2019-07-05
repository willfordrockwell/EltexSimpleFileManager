#include "graph.h"

void Init_Tab(struct Tab *Tab, int Tab_Height, int Tab_Length, int Start_Y,
              int Start_X)
{
    int Size_Length = 10;
    int Time_Length = 13;
    int Name_Length = Tab_Length - Size_Length - Time_Length - 2;
    Tab->Tab = newwin(Tab_Height, Tab_Length, Start_Y, Start_X);

    Tab->Name = derwin(Tab->Tab, Tab_Height - 2, Name_Length, 1, 1);
    if (Tab->Name == NULL) {
        fprintf(stderr, "Error Name\n");
    }

    Tab->Size = derwin(Tab->Tab, Tab_Height - 2, Size_Length, 1, 
                       Name_Length + 1);

    if (Tab->Size == NULL) {
        fprintf(stderr, "Error Size\n");
    }

    Tab->Time = derwin(Tab->Tab, Tab_Height - 2, Time_Length, 1,
                       Name_Length + Size_Length + 1);

    if (Tab->Time == NULL) {
        fprintf(stderr, "Error Time\n");
    }

    wbkgd(Tab->Name, COLOR_PAIR(1));
    wbkgd(Tab->Size, COLOR_PAIR(1));
    wbkgd(Tab->Time, COLOR_PAIR(1));

    wattron(Tab->Name, A_NORMAL);
    wattron(Tab->Size, A_NORMAL);
    wattron(Tab->Time, A_NORMAL);

    keypad(Tab->Tab, 1);
    keypad(Tab->Name, 1);
    keypad(Tab->Size, 1);
    keypad(Tab->Time, 1);
    
    #ifndef DEBUG
        curs_set(0);
        Refresh_Tab(Tab);
    #endif
}