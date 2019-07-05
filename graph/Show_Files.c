#include "graph.h"

void Show_Files(struct Tab *Tab, struct File_Info *Directory, int Files_Count,
                int File_Selection, int Start_File, int Rows, int Cols_Name,
                int Cols_Time, int Cols_Size) 
{
    //erase window
    werase(Tab->Name);
    werase(Tab->Size);
    werase(Tab->Time);

    int Files_To_Print = (Rows > Files_Count) ? Files_Count : Rows;
    for (int i = 0; i < Start_File; i++) {
        Directory++;
    }
    for (int i = Start_File; i < Start_File + Files_To_Print; i++) {
        Set_Window_Attr(Tab, File_Selection, Directory->Is_Dir, i);

        Out_Str_Window(
            Tab->Name,
            i - Start_File,
            0,
            Directory->Name,
            strlen(Directory->Name)
        );
        Out_Str_Window(
            Tab->Size,
            i - Start_File,
            0,
            Directory->Size,
            strlen(Directory->Size)
        );
        Out_Str_Window(
            Tab->Time,
            i - Start_File,
            0,
            Directory->Time,
            strlen(Directory->Time)
        );

        Reset_Window_Attr(Tab, File_Selection, Directory->Is_Dir, i);
        
        Directory++;
    }
    #ifndef DEBUG
        Refresh_Tab(Tab);
    #endif
}