#ifndef __LOGIC_H__
#define __LOGIC_H__ 
#include <sys/types.h>
#include <sys/stat.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>

struct File_Info {
    char Name[256];
    char Size[10];
    char Time[26];
    int Is_Dir;
};

struct File_Info *Open_Folder(char *Dir_Name, int *Files_Count);

char* Get_Folder_Up (char *Input);

void Change_Dir(struct File_Info **Files_1, struct File_Info **Files_2,
                struct File_Info **Files_C, int *Files_Count_1,
                int *Files_Count_2, char *Dir_Name_1, char *Dir_Name_2, 
                int *File_Sel_1, int *File_Sel_2, int *Lower_Bound_1,
                int *Lower_Bound_2, int *Upper_Bound_1, int *Upper_Bound_2,
                int Rows);

void Folder_Up (struct File_Info **Files_1, struct File_Info **Files_2,
                struct File_Info **Files_C, int *Files_Count_1,
                int *Files_Count_2, char *Dir_Name_1, char *Dir_Name_2, 
                char *Dir_Name_C, int *File_Sel_1, int *File_Sel_2, 
                int **File_Sel_C, int *Lower_Bound_1, int *Lower_Bound_2,
                int *Upper_Bound_1, int *Upper_Bound_2, int Rows);
#endif // !__LOGIC_H__
