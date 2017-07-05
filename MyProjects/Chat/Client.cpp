#include <WinSock2.h>
#include <iostream>
#include <ctime>
#include <WS2tcpip.h>

SOCKET Client;

char name[24];

void SendMessageToClient() {
    char out[1024];
    for (;; Sleep(75)) {
        for(int i = 0; i < 1024; i++) out[i] = 0;
        if (recv(Client, out, 1024, 0) > 0) {
            printf(out);
            printf("\n");
        }
    }
}

int main() {
    system("chcp 1251"); system("cls");
    char message[1024];
    char in[1014];
    char adrserv[INET_ADDRSTRLEN];
    FILE* f = fopen("info.txt", "r");
    if(!f)
        return 321;
    int port;
    WSAData data;
    WORD version = MAKEWORD(2, 2);
    int res = WSAStartup(version, &data);
    if (res != 0) {
        return 0;
    }
    Client = socket(AF_INET, SOCK_STREAM, 0);
    if (Client < 0) {
        printf("Socket() error %d\n", WSAGetLastError());
        return -1;
    }
    printf("Inputed port: ");
    fscanf(f, "%d\n", &port);
    std::cout << port << std::endl;
    printf("Inputed ip: ");
    fscanf(f, "%s\n", &adrserv);
    std::cout << adrserv << std::endl;
    struct sockaddr_in connect_c;
    connect_c.sin_family = AF_INET;
    connect_c.sin_port = htons(port);
    HOSTENT *hst;
    if (inet_addr(adrserv) != INADDR_NONE)
        connect_c.sin_addr.s_addr = inet_addr(adrserv);
    else {
        if (hst = gethostbyname(adrserv))
            ((unsigned long *)&connect_c.sin_addr)[0] =
                    ((unsigned long **)hst->h_addr_list)[0][0];
        else {
            printf("Invalid address: %s\n", adrserv);
            closesocket(Client);
            WSACleanup();
            return -1;
        }
    }
    if (connect(Client, (sockaddr *)&connect_c, sizeof(connect_c))) {
        printf("Connect error %d\n", WSAGetLastError());
        return -1;
    }
    printf("Connect is OK!\n");
    printf("Inputed name: ");
    fscanf(f, "%s\n", &name);
    std::cout << name << std::endl;
    fclose(f);
    strcat(name, ": ");
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)SendMessageToClient, CreateMutex(NULL, FALSE, NULL), NULL, NULL);
    do {
        for(int i = 0; i < 1024; i++) message[i] = 0;
        strcpy(message, name);
        fflush(stdin);
        gets(in);
        if(strcmp(in, "exit") == 0) break;
        strcat(message, in);
        send(Client, message, strlen(message), 0);
    } while (1);
    closesocket(Client);
    WSACleanup();
    return 0;
}