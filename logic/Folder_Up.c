#include "logic.h"

void Folder_Up (struct File_Info **Files_1, struct File_Info **Files_2,
                struct File_Info **Files_C, int *Files_Count_1,
                int *Files_Count_2, char *Dir_Name_1, char *Dir_Name_2, 
                char *Dir_Name_C, int *File_Sel_1, int *File_Sel_2, 
                int **File_Sel_C, int *Lower_Bound_1, int *Lower_Bound_2,
                int *Upper_Bound_1, int *Upper_Bound_2, int Rows)
{
    Dir_Name_C = Get_Folder_Up(Dir_Name_C);
    for (int i = (**File_Sel_C); i > 0; i--){
        (*Files_C)--;
    }
    Change_Dir(Files_1, Files_2, Files_C, Files_Count_1, Files_Count_2,
               Dir_Name_1, Dir_Name_2, File_Sel_1, File_Sel_2, Lower_Bound_1,
               Lower_Bound_2, Upper_Bound_1, Upper_Bound_2, Rows);
}