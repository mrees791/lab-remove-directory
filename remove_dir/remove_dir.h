#ifndef REMOVE_DIR_H
#define REMOVE_DIR_H

#include <stdbool.h>

char * create_path(char * path, char * filename);
bool is_valid_dir(char * currentPath);
void delete_dir(char * dirPath);
void delete_file(char * dirFile);
void empty_dir(char * currentPath);
void delete_requested_folder(char * folderName);
void notify_user_cancellation();

#endif
