#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <curses.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "../logic/logic.h"

struct Tab {
    WINDOW *Tab;
    WINDOW *Name;
    WINDOW *Size;
    WINDOW *Time;
};

void Sig_Winch(int signo);

void Init(struct Tab *First, struct Tab *Second, int Rows, int Cols);

void Init_Tab(struct Tab *Tab, int Tab_Height, int Tab_Length, int Start_Y,
              int Start_X);

void Refresh_Tab (struct Tab *Tab);

struct Tab *Switch_Tab (struct Tab *First, struct Tab *Second,
                        struct Tab *Current);

void Set_Window_Attr(struct Tab *Tab, int File_Selection, int Is_Dir,
                     int Counter);

void Reset_Window_Attr(struct Tab *Tab, int File_Selection, int Is_Dir,
                       int Counter);

void Delete_Tab(struct Tab *Tab);

void Out_Window_Title (WINDOW *Wnd, char *Title);

void Out_Str_Window(WINDOW *Wnd, int Start_Y, int Start_X, char *Input,
                    int Length);

void Show_Files(struct Tab *Tab, struct File_Info *Directory, int Files_Count,
                int File_Selection, int Start_File, int Rows, int Cols_Name,
                int Cols_Time, int Cols_Size);

void End_Window();
#endif
