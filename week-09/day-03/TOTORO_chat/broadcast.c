#include "broadcast.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <process.h>
#include <winsock2.h>
#include <time.h>

void broadcast_server()
{
    WSADATA wsa;
    SOCKET server_socket;
    struct sockaddr_in server_address, client_address;
    int recv_bytes;
    unsigned int clientLength;
    char message[4096];
    char client_reply[4096];
    time_t clk;
    FILE *server_log;

    server_log = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-03\\broadcast\\broadcast_log.txt", "a+");
    if (server_log == NULL) {
        printf("\nCannot open file \n\n");
        exit(0);
    }

    clk = time(NULL);
    printf("%s", ctime(&clk));
    fprintf(server_log, "\n%s", ctime(&clk));
    printf("Initialising Winsock...\n\n");
    fprintf(server_log, "Initialising Winsock...\n\n");

    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(server_log, "%s", ctime(&clk));
        printf("Failed. Error Code : %d\n\n",WSAGetLastError());
        fprintf(server_log, "Failed. Error Code : %d\n\n",WSAGetLastError());
        return 1;
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(server_log, "%s", ctime(&clk));
        printf("Initialised.\n\n");
        fprintf(server_log, "Initialised.\n\n");
    }

    if((server_socket = socket(AF_INET , SOCK_DGRAM , 0)) == INVALID_SOCKET) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(server_log, "%s", ctime(&clk));
        printf("Could not create socket : %d\n\n" , WSAGetLastError());
        fprintf(server_log, "Could not create socket : %d\n\n" , WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(server_log, "%s", ctime(&clk));
        printf("Socket created.\n\n");
        fprintf(server_log, "Socket created.\n\n");
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("10.27.6.125");
    server_address.sin_port = htons(1234);

    if( bind(server_socket ,(struct sockaddr *)&server_address , sizeof(server_address)) == SOCKET_ERROR) {
        clk = time(NULL);
        printf("\n%s", ctime(&clk));
        fprintf(server_log, "\n%s", ctime(&clk));
        printf("Bind failed with error code : %d\n\n" , WSAGetLastError());
        fprintf(server_log, "Bind failed with error code : %d\n\n" , WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("\n%s", ctime(&clk));
        fprintf(server_log, "\n%s", ctime(&clk));
        puts("Bind done.\n");
        fputs("Bind done.\n", server_log);
    }

    listen(server_socket , 3);

    clk = time(NULL);
    printf("%s", ctime(&clk));
    fprintf(server_log, "\n%s", ctime(&clk));
    puts("Waiting for incoming data...\n");
    fputs("Waiting for incoming data...\n", server_log);

    fclose(server_log);

   while(1) {

        server_log = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-03\\broadcast\\broadcast_log.txt", "a+");
        if (server_log == NULL) {
            printf("\nCannot open file \n\n");
            exit(0);
        }

        clientLength = sizeof(client_address);
        recv_bytes= recvfrom(server_socket, message, 4096, 0, (struct sockaddr*) &client_address, &clientLength);

        if(recv_bytes == SOCKET_ERROR) {
            clk = time(NULL);
            printf("\n%s", ctime(&clk));
            fprintf(server_log, "\n%s", ctime(&clk));
            puts("recv failed.\n");
            fputs("recv failed.\n", server_log);
        } else {
            clk = time(NULL);
            printf("\n%s", ctime(&clk));
            fprintf(server_log, "\n\n%s", ctime(&clk));
            printf("SERVER: read %d bytes from IP %s(%s)\n", recv_bytes, inet_ntoa(client_address.sin_addr), message);
            fprintf(server_log, "SERVER: read %d bytes from IP %s(%s)\n", recv_bytes, inet_ntoa(client_address.sin_addr), message);
        }

        fclose(server_log);
    }

    closesocket(server_socket);
    WSACleanup();
    fclose(server_log);
}


void broadcast_send_message()
{
    WSADATA wsa;
    SOCKET clientToServer_socket;
    char buf[512];
    unsigned int fromLength;
    struct sockaddr_in Remote_Address, Server_Address;
    struct hostent *hostPointer;
    int message, checkCall;
    int broadcastOn = 1;
    int broadcastOff = 0;
    char *broadcastMessage;
    time_t clk;
    FILE *client_log;

    broadcastMessage = "TOTORO 15000";

    printf("Message %s\n", broadcastMessage);

    client_log = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-03\\broadcast\\broadcast_log.txt", "a+");
    if (client_log == NULL) {
        printf("\nCannot open file \n\n");
        exit(0);
    }

    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(client_log, "%s", ctime(&clk));
        printf("Failed. Error Code : %d\n\n",WSAGetLastError());
        fprintf(client_log, "Failed. Error Code : %d\n\n",WSAGetLastError());
        return 1;
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(client_log, "%s", ctime(&clk));
        printf("Initialised.\n\n");
        fprintf(client_log, "Initialised.\n\n");
    }

    if((clientToServer_socket = socket(AF_INET , SOCK_DGRAM , 0)) == INVALID_SOCKET) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(client_log, "%s", ctime(&clk));
        printf("Could not create socket : %d\n\n" , WSAGetLastError());
        fprintf(client_log, "Could not create socket : %d\n\n" , WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        fprintf(client_log, "%s", ctime(&clk));
        printf("Socket created.\n\n");
        fprintf(client_log, "Socket created.\n\n");
    }

    Remote_Address.sin_family=AF_INET;
    Remote_Address.sin_addr.s_addr = inet_addr("255.255.255.255");
    Remote_Address.sin_port=htons(1234);


   checkCall = setsockopt(clientToServer_socket, SOL_SOCKET, SO_BROADCAST, &broadcastOn, 4);
   if(checkCall == -1)
        perror("Error: Second setsockopt call failed");

   int broadcastMessageLen = strlen(broadcastMessage) + 1;

   printf("Message test %d\n", broadcastMessageLen);

   message = sendto(clientToServer_socket, broadcastMessage, broadcastMessageLen, 0, (struct sockaddr *) &Remote_Address, sizeof(Remote_Address));

   if (message ==-1)
        perror("Error: sendto call failed");

   close(clientToServer_socket);
}
