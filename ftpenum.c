/*
Author: Igor M. Martins
*/
#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>

int main(int argc, char** argv){
  //usage: ./ftpenum [ADDRESS]
	int meusocket;
	int conecta;
	int porta;
	struct sockaddr_in alvo;

	meusocket = socket(AF_INET,SOCK_STREAM,0);
	alvo.sin_family = AF_INET;
	if (argc >= 2){
		porta = atoi(argv[2]);
	}else{
		porta = 21;
	}
	alvo.sin_port = htons(porta);
	alvo.sin_addr.s_addr = inet_addr(argv[1]);

	conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);
	

	if(conecta == 0){
		printf("[+] Porta aberta \n");
	}else{
		printf("[-] Porta fechada \n");
	}
	close(meusocket);
}
