#include "logic.h"

char* Get_Folder_Up (char *Input)
{
    for (int i = strlen(Input); Input[i] != '/'; i--) {
        Input[i] = '\0';
    }
    if (strlen(Input) != 1) {
        Input[strlen(Input) - 1] = '\0';
    }
    return Input;
}