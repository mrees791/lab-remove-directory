
// Michael Rees
// Operating Systems - Remove Directory Application
// This program will prompt a user for a directory to delete then delete the directory contents.

#include <stdio.h> 
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

void myUbuntuTest() {
    printf("test2\n");
}

char * create_path(char * path, char * filename) {
    int len = 1 + strlen(path) + strlen(filename);
    char * newPath = malloc(len);
    sprintf(newPath, "%s/%s", path, filename);
    
    return newPath; 
}

bool is_valid_dir(char * currentPath) {
    bool isValidDirectory = true;

    if (strcmp(currentPath, ".") == 0) {
        isValidDirectory = false;
    }
    if (strcmp(currentPath, "..") == 0) {
        isValidDirectory = false;
    }

    return isValidDirectory;
}

void delete_dir(char * dirPath) {
    printf("Deleting Directory:%s\n", dirPath);
    int success = rmdir(dirPath);
    if (success == 0) {
        printf("Success\n");
    } else {
        printf("Failed\n");
    }
}

void delete_file(char * dirFile) {
    printf("Deleting File:%s\n", dirFile);
    int success = remove(dirFile);
    if (success == 0) {
        printf("Success\n");
    } else {
        printf("Failed\n");
    }
}

void empty_dir(char * currentPath) {
    DIR * currentDir = opendir(currentPath);
    
    struct dirent * currentDirent = readdir(currentDir);

    while (currentDirent != NULL) {
        bool isFile = currentDirent->d_type == DT_REG;
        bool isDirectory = currentDirent->d_type == DT_DIR;

        if (isDirectory) {
            bool isValidDirectory = is_valid_dir(currentDirent->d_name);
            char * nextPath = create_path(currentPath, currentDirent->d_name);

            if (isValidDirectory) {
                empty_dir(nextPath);
            }
            free(nextPath);
        } else if (isFile) {
            char * filePath = create_path(currentPath, currentDirent->d_name);
            delete_file(filePath);
            free(filePath);
        }
        currentDirent = readdir(currentDir);
    }
    
    free(currentDir);
    delete_dir(currentPath);
}

void delete_requested_folder(char * folderName) {
    printf("Deletion confirmed.\n");
    char * currentPath = create_path(".", folderName);
    empty_dir(currentPath);
    free(currentPath);
}

void notify_user_cancellation() {
    printf("Deletion cancelled.\n");
}

int main() {
    char * folderName = malloc(50);
    char * choice = malloc(1);

    printf("Remove Directory App\n");
    printf("Enter the folder name:");
    scanf("%s", folderName);

    printf("You Entered:%s.\nAre you sure you want to delete it and its contents? (y for yes, n for no)\n", folderName);
    scanf("%s", choice);

    bool deletionConfirmed = choice[0] == 'y';

    if (deletionConfirmed) {
        delete_requested_folder(folderName);
    } else {
        notify_user_cancellation();
    }

    free(folderName);
    free(choice);

    return 0;
} 
