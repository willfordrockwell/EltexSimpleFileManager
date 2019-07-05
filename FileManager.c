#include "FileManager.h"

int main(int argc, char **argv)
{
    struct Tab *Tab_1 = (struct Tab*) malloc(sizeof(struct Tab));

    struct Tab *Tab_2 = (struct Tab*) malloc(sizeof(struct Tab));

    struct Tab *Tab_C = Tab_1;
    
    struct winsize Terminal_Size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char*)&Terminal_Size);

    int Rows = Terminal_Size.ws_row;
    int Cols = Terminal_Size.ws_col;

    int Cols_Time = 26;
    int Cols_Size = 4;
    int Cols_Name = (Cols / 2) - Cols_Time - Cols_Size;

    Init(Tab_1, Tab_2, Rows, Cols);

    Tab_C = Tab_1;

    int Dir_Name_Size = 255;
    char *Dir_Name_1 = (char*) malloc (Dir_Name_Size * sizeof(char));
    char *Dir_Name_2 = (char*) malloc (Dir_Name_Size * sizeof(char));
    char *Dir_Name_C = Dir_Name_1;

    getcwd(Dir_Name_1, Dir_Name_Size);
    getcwd(Dir_Name_2, Dir_Name_Size);

    int Files_Count_1 = 0;
    int Files_Count_2 = 0;
    int *Files_Count_C = &Files_Count_1;

    struct File_Info *Files_1 = Open_Folder(Dir_Name_1, &Files_Count_1);

    struct File_Info *Files_2 = Open_Folder(Dir_Name_2, &Files_Count_2);

    struct File_Info *Files_C = Files_1;

    int File_Sel_1 = 0;
    int File_Sel_2 = 0;
    int *File_Sel_C = &File_Sel_1;

    int Lower_Bound_1 = Rows - 2;
    int Lower_Bound_2 = Rows - 2;
    int *Lower_Bound_C = &Lower_Bound_1;

    int Upper_Bound_1 = 0;
    int Upper_Bound_2 = 0;
    int *Upper_Bound_C = &Upper_Bound_1;

    int command = '\0';

    Show_Files(Tab_1, Files_1, Files_Count_1, File_Sel_1, Upper_Bound_1, Rows,
               Cols_Name, Cols_Time, Cols_Size);
    Show_Files(Tab_2, Files_2, Files_Count_2, File_Sel_2, Upper_Bound_2, Rows,
               Cols_Name, Cols_Time, Cols_Size);
    
    while (command != 'q') {
        switch (command)
        {
        case '\t':
            //Switch Tab
            File_Sel_C = CHANGE_INTS(File_Sel_C, File_Sel_1, File_Sel_2);

            Lower_Bound_C = CHANGE_INTS(Lower_Bound_C, Lower_Bound_1,
                                        Lower_Bound_2);

            Upper_Bound_C = CHANGE_INTS(Upper_Bound_C, Upper_Bound_1,
                                        Upper_Bound_2);

            Files_Count_C = CHANGE_INTS(Files_Count_C, Files_Count_1,
                                        Files_Count_2);

            Dir_Name_C = CHANGE_POINTERS(Dir_Name_C, Dir_Name_1, Dir_Name_2);
            Files_C = CHANGE_POINTERS(Files_C, Files_1, Files_2);
            Tab_C = CHANGE_POINTERS(Tab_C, Tab_1, Tab_2);
            break;

        case KEY_DOWN:
            //list down
            if ((*Files_Count_C) - 1 == *File_Sel_C) {
                break;
            }
            if (*File_Sel_C == ((*Lower_Bound_C) - 1)) {
                (*Lower_Bound_C) += Rows - 2;
                (*Upper_Bound_C) += Rows - 2;
            }
            (*File_Sel_C)++;

            Show_Files(Tab_C, Files_C, *Files_Count_C, *File_Sel_C,
                       *Upper_Bound_C, Rows, Cols_Name, Cols_Time, Cols_Size);
            break;

        case KEY_UP:
            //list up
            if (*File_Sel_C == 0) {
                break;
            }
            if (*File_Sel_C == *Upper_Bound_C) {
                (*Lower_Bound_C) -= Rows - 2;
                (*Upper_Bound_C) -= Rows - 2;
            }
            (*File_Sel_C)--;

            Show_Files(Tab_C, Files_C, *Files_Count_C, *File_Sel_C,
                       *Upper_Bound_C, Rows, Cols_Name, Cols_Time, Cols_Size);
            break;

        case '\n':
            for (int i = 0; i < *File_Sel_C; i++) {
                Files_C++;
            }

            if (Files_C->Is_Dir){
                //This folder
                if (strncmp(Files_C->Name, ".", strlen(Files_C->Name)) == 0) {
                    for (int i = (*File_Sel_C); i > 0; i--){
                        Files_C--;
                    }
                    (*File_Sel_C) = 0;
                    (*Upper_Bound_C) = 0;
                    (*Lower_Bound_C) = Rows - 2;
                }
                //Folder up
                if (strncmp(Files_C->Name, "..", strlen(Files_C->Name)) == 0) {
                    Folder_Up (&Files_1, &Files_2, &Files_C, &Files_Count_1,
                               &Files_Count_2, Dir_Name_1, Dir_Name_2,
                               Dir_Name_C, &File_Sel_1, &File_Sel_2,
                               &File_Sel_C, &Lower_Bound_1, &Lower_Bound_2, 
                               &Upper_Bound_1, &Upper_Bound_2, Rows);
                }
                //Other folder
                else {
                    strcat(Dir_Name_C, "/");
                    strcat(Dir_Name_C, Files_C->Name);
                    for (int i = (*File_Sel_C); i > 0; i--){
                        Files_C--;
                    }
                    Change_Dir(&Files_1, &Files_2, &Files_C, &Files_Count_1,
                               &Files_Count_2, Dir_Name_1, Dir_Name_2,
                               &File_Sel_1, &File_Sel_2, &Lower_Bound_1,
                               &Lower_Bound_2, &Upper_Bound_1, &Upper_Bound_2,
                               Rows);
                }
            }
            //file
            else {
                //
                for (int i = (*File_Sel_C); i > 0; i--){
                    Files_C--;
                }
            }
            Show_Files(Tab_C, Files_C, *Files_Count_C, *File_Sel_C, 
                       *Upper_Bound_C, Rows, Cols_Name, Cols_Time, Cols_Size);
            break;
            
        default:

            break;
        }
        command = wgetch(stdscr);
    }
    
    Delete_Tab(Tab_1);
    Delete_Tab(Tab_2);

    free(Files_1);
    free(Files_2);

    free(Tab_1);
    free(Tab_2);
    endwin();
    return 0;
}
