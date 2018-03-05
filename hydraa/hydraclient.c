/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydraclient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 13:10:51 by stestein          #+#    #+#             */
/*   Updated: 2018/03/03 18:02:20 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(char *msg)
{
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[])
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];

	if (argc < 3)
	{
		printf(stderr,"usage %s hostname port\n", argv[0]);
		exit(0);
	}

	portno = atoi(argv[2]);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0)
		error("Error opening socket");
	server = gethostbyname(argv[1]);
	if (server == NULL)
	{
		printf(stderr, "Error, no such host\n");
		exit (0);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;i

	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,server->h_length);

	serv_addr.sin_port = htons(portno);

	if (connect(sockfd,&serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR connecting");
	printf("Command to send to server: ");
	bzero(buffer,256);
	fgets(buffer,255,stdin);

	n = write(sockfd,buffer,strlen(buffer));
	
	if (n < 0)
		error("Error reading from server");
	bzero(buffer,256);
	n = read(sockfd,buffer,255);
	
	if (n < 0)
		error("ERROR reading from socket");
	printf("%s\n",buffer);

	return 0;
}

