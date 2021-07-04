#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 80
#define PORT 50000

void chat(int socketfd) {
  char buffer[BUFFER_SIZE];
  int n;

  while (true) {
    bzero(buffer, BUFFER_SIZE);
    read(socketfd, buffer, sizeof(buffer));
    printf("From client: %sTo client: ", buffer);
    bzero(buffer, BUFFER_SIZE);
    n = 0;
    while ((buffer[n++] = getchar()) != '\n')
      ;
    write(socketfd, buffer, sizeof(buffer));
    if (strncmp("exit", buffer, 4) == 0) {
      printf("Server Exit...\n");
      break;
    }
  }
}

int main() {
  int socketfd, connectionfd;
  struct sockaddr_in server_addr, client_addr;

  if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    printf("Socket creation failed!\n");
    exit(0);
  } else {
    printf("Socket successfully created!\n");
  }
  bzero(&server_addr, sizeof(server_addr));

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PORT);

  if (bind(socketfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) !=
      0) {
    printf("Socket bind failed!\n");
    exit(0);
  } else {
    printf("Socket successfully binded!\n");
  }

  if ((listen(socketfd, 5)) != 0) {
    printf("Listen failed!\n");
    exit(0);
  } else {
    printf("Server listening...\n");
  }
  int len = sizeof(client_addr);

  connectionfd =
      accept(socketfd, (struct sockaddr*)&client_addr, (socklen_t*)&len);
  if (connectionfd < 0) {
    printf("Server acccept failed!\n");
    exit(0);
  } else {
    printf("Server acccepted the client!\n");
  }

  chat(connectionfd);
  close(socketfd);

  return 0;
}