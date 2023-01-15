
// Michael Rees
// Operating Systems - Remove Directory Application
// This program will prompt a user for a directory to delete then delete the
// directory contents.

#include "remove_dir/remove_dir.h"
#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char *dirPath = malloc(255);
  char *choice = malloc(1);

  printf("Remove Directory App\n");
  printf("Enter the directory to delete:\n");
  scanf("%s", dirPath);
  printf("Are you sure? (y for yes, n for no)\n");
  scanf("%s", choice);

  bool deletionConfirmed = choice[0] == 'y';

  if (deletionConfirmed) {
    delete_requested_folder(dirPath);
  } else {
    notify_user_cancellation();
  }

  free(dirPath);
  free(choice);

  return 0;
}
