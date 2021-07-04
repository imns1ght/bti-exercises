// Server side implementation of UDP client-server model
#include <arpa/inet.h>  // htons
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>  // socket()
#include <sys/types.h>   // socket()
#include <unistd.h>

#include <iostream>
#include <string>

#define PORT 8080
#define MAXLINE 1024

int main() {
  struct sockaddr_in server_addr;
  int sockfd;
  char buffer[MAXLINE];
  char *hello = "Client: Hello!";

  // Creates an endpoint for communication
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    std::cerr << "Server: Socket creation failed" << std::endl;
    exit(EXIT_FAILURE);
  }

  // Fill server information
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;  // IPv4
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  int len;
  sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM,
         (const struct sockaddr *)&server_addr, sizeof(server_addr));
  std::cout << "Client: Message sent!" << std::endl;
  int n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL,
                   (struct sockaddr *)&server_addr, (socklen_t *)&len);
  buffer[n] = '\0';
  std::cout << buffer << std::endl;

  close(sockfd);

  return 0;
}
