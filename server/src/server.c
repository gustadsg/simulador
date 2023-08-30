#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "server.h"
#include "constants.h"
#include "simulator.h"

int create_pipe(char* pipe_path) {
  return mkfifo(pipe_path, 0777) != -1;
}

int write_to_pipe(int file_descriptor, void * content) {
  return write(file_descriptor, &content, sizeof(content)) != -1;
}


int main() {
  // Create named pipe
  int pipe_created = create_pipe(PIPE_NAME);
  if (!pipe_created) {
    if (errno != EEXIST) {
      printf("Could not create pipe");
      return ERROR_CREATING_PIPE;
    }
  }

  // Create file descriptor
  int file_descriptor = open(PIPE_NAME, O_WRONLY);

  // Generate content to be written
  int content = simulate(1);

  // Try to write into file
  int wrote_successfully = write_to_pipe(file_descriptor,(void *) content);
  if (!wrote_successfully) {
    printf("Could not write into pipe");
    return ERROR_WRITING_PIPE;
  }

  // Close file
  close(file_descriptor);

  return 0;
}