#include "logic.h"

void Change_Dir(struct File_Info **Files_1, struct File_Info **Files_2,
                struct File_Info **Files_C, int *Files_Count_1,
                int *Files_Count_2, char *Dir_Name_1, char *Dir_Name_2, 
                int *File_Sel_1, int *File_Sel_2, int *Lower_Bound_1,
                int *Lower_Bound_2, int *Upper_Bound_1, int *Upper_Bound_2,
                int Rows)
{
    if (*Files_1 == *Files_C) {
        free(*Files_1);
        *Files_Count_1 = 0;
        *Files_1 = Open_Folder(Dir_Name_1, Files_Count_1);
        *Files_C = *Files_1;
        *File_Sel_1 = 0;
        *Lower_Bound_1 = Rows - 2;
        *Upper_Bound_1 = 0;
    }
    else {
        free(*Files_2);
        *Files_Count_2 = 0;
        *Files_2 = Open_Folder(Dir_Name_2, Files_Count_2);
        *Files_C = *Files_2;
        *File_Sel_2 = 0;
        *Lower_Bound_2 = Rows - 2;
        *Upper_Bound_2 = 0;
    }
}