#include "logic.h"

static int Compare_Name (const void *p1, const void *p2)
{
    struct File_Info *par1 = (struct File_Info*)p1;
    struct File_Info *par2 = (struct File_Info*)p2;
    return strcmp(par1->Name, par2->Name);
}

static int Compare_Dir (const void *p1, const void *p2)
{
    struct File_Info *par1 = (struct File_Info*)p1;
    struct File_Info *par2 = (struct File_Info*)p2;
    return (par1->Is_Dir > par2->Is_Dir) ? -1 : (par1->Is_Dir < par2->Is_Dir) ? 1 : 0;
}

struct File_Info *Open_Folder(char *Dir_Name, int *Files_Count)
{
    DIR *Dir;
    
    struct File_Info *Current_File_Info =
    (struct File_Info*) malloc (sizeof(struct File_Info));
    
    struct stat *Stat_File = (struct stat*) malloc (sizeof(struct stat));
    struct dirent *Entry;

    int Dir_Name_Length = strlen(Dir_Name);
    int Time_Length;
    Dir = opendir(Dir_Name);
    if (!Dir) {
        perror("diropen");
        exit(1);
    };
    strcat(Dir_Name, "/");
    Dir_Name_Length++;
    while ( (Entry = readdir(Dir)) != NULL) {
        (*Files_Count)++;

        Current_File_Info = 
        (struct File_Info*) realloc (
            Current_File_Info, 
            (*Files_Count) * sizeof(struct File_Info)
        );

        for (int i = 0; i < (*Files_Count) - 1; i++) {
            Current_File_Info++;
        }

        //clean from previous filename
        for (int i = Dir_Name_Length; i < strlen(Dir_Name); i++) {
            Dir_Name[i] = '\0';
        }
        strcpy(Current_File_Info->Name, Entry->d_name);
        strcat(Dir_Name, Current_File_Info->Name);

        if(stat(Dir_Name, Stat_File) == -1) {
            fprintf(stderr, "%s\n", strerror(errno));
            exit(1);
        }

        //strcpy(Current_File_Info->Size, Stat_File->st_size);
        sprintf(Current_File_Info->Size, "%d", Stat_File->st_size);

        strcpy(Current_File_Info->Time, ctime(&(Stat_File->st_mtime)));

        for (int i = 0; i < strlen(Current_File_Info -> Time); i++){
            if (i < 6) {
                Current_File_Info->Time[i] = 
                Current_File_Info->Time[i + 4];
            }
            else if (i < 11) {
                Current_File_Info->Time[i] = 
                Current_File_Info->Time[i + 13];
            }
            else {
                Current_File_Info->Time[i] = '\0';
            }
        }

        if(S_ISDIR(Stat_File->st_mode)) {
            Current_File_Info->Is_Dir = 1;
        }
        else {
            Current_File_Info->Is_Dir = 0;
        }

        for (int i = (*Files_Count) - 1; i > 0; i--) {
            Current_File_Info--;
        }
    }

    //TODO: SORT
    qsort(Current_File_Info, *Files_Count, sizeof(struct File_Info), Compare_Name);
    qsort(Current_File_Info, *Files_Count, sizeof(struct File_Info), Compare_Dir);

    for (int i = Dir_Name_Length; i < strlen(Dir_Name); i++) {
        Dir_Name[i] = '\0';
    }
    Dir_Name[strlen(Dir_Name) - 1] = '\0';
    
    closedir(Dir);
    free(Stat_File);
    return Current_File_Info;
}