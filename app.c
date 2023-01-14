
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
  char *folderName = malloc(50);
  char *choice = malloc(1);

  printf("Remove Directory App\n");
  printf("Enter the folder name:");
  scanf("%s", folderName);

  printf("You Entered:%s.\nAre you sure you want to delete it and its "
         "contents? (y for yes, n for no)\n",
         folderName);
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
