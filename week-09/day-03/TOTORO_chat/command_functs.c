#include "command_functs.h"
#include "broadcast.h"
#include "message.h"
#include "discovery_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <winsock2.h>
#include <time.h>
#include <windows.h>

void wsa_init()
{
    WSADATA wsa;
    time_t clk;

    clk = time(NULL);
    printf("%s", ctime(&clk));
    printf("Initialising Winsock...\n\n");

    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Failed. Error Code : %d\n\n",WSAGetLastError());
    } else {
        clk = time(NULL);
        printf("%s", ctime(&clk));
        printf("Initialised.\n\n");
    }
}

void startup_com_list()
{
    FILE *commandlist = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-03\\TOTORO_chat\\commandlist.txt", "r");
    if(commandlist == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    char c;
    c = fgetc(commandlist);
    while (c != EOF) {
        printf ("%c", c);
        c = fgetc(commandlist);
    }
    fclose(commandlist);
    printf("\n\n");
}

void print_command_list()
{
    FILE *commandlist = fopen("C:\\Users\\Adam\\Desktop\\greenfox\\BercziAdam\\week-09\\day-03\\TOTORO_chat\\commandlist.txt", "r");
    if(commandlist == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    char c;
    c = fgetc(commandlist);
    while (c != EOF) {
        printf ("%c", c);
        c = fgetc(commandlist);
    }
    fclose(commandlist);
    printf("\n\n");
}

void print_user_list(user_t user_array, int user_index)
{
    printf("IP address \t Discovery port number \n");
    //for(int i = 0; i <= user_index; i++)
        //printf("%s \t %d \n", user_array[i].discovery_port_number, user_array[i].discovery_port_number);
}

