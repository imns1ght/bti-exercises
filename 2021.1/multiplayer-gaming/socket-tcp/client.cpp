#include <arpa/inet.h>
#include <netdb.h>
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
    bzero(buffer, sizeof(buffer));
    printf("To server: ");
    n = 0;
    while ((buffer[n++] = getchar()) != '\n')
      ;
    write(socketfd, buffer, sizeof(buffer));
    bzero(buffer, sizeof(buffer));
    read(socketfd, buffer, sizeof(buffer));
    printf("From Server: %s", buffer);
    if ((strncmp(buffer, "exit", 4)) == 0) {
      printf("Client Exit...\n");
      break;
    }
  }
}

int main() {
  int socketfd;
  struct sockaddr_in server_addr, client_addr;

  if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    printf("Socket creation failed!\n");
    exit(0);
  } else {
    printf("Socket successfully created!\n");
  }
  bzero(&server_addr, sizeof(server_addr));

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_addr.sin_port = htons(PORT);

  if (connect(socketfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) !=
      0) {
    printf("Connection with the server failed! :(\n");
    exit(0);
  } else {
    printf("Connected to the server!\n");
  }

  chat(socketfd);
  close(socketfd);

  return 0;
}
