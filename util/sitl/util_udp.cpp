#include "util_udp.h"
#include <unistd.h>
#include <netinet/ip.h>
#include <netdb.h>

#define DEC_PORT_SIZE 16

/**
 * @brief Base class for UDP connection (Constructor)
 * 
 * @param addr - IP Adress as string
 * @param port - Port to connect
 */
Udp_base::Udp_base(const std::string &addr, int port) : m_port(port),m_addr(addr) {

	char dec_port[DEC_PORT_SIZE];
	snprintf(dec_port, DEC_PORT_SIZE,"%d",m_port);
	dec_port[DEC_PORT_SIZE-1] = '\0';
	
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
	
	int r(getaddrinfo(addr.c_str(), dec_port, &hints, &m_addrinfo));
	if(r != 0 || m_addrinfo == NULL) {
		perror("error on r");
	}
	m_socket = socket(m_addrinfo->ai_family, SOCK_DGRAM | SOCK_CLOEXEC, IPPROTO_UDP);
	if(m_socket == -1) {
		freeaddrinfo(m_addrinfo);
		perror("error on socket");
	}
}

/**
 * @brief Base class for UDP connection (Destructor)
 * 
 */
Udp_base::~Udp_base() {
	freeaddrinfo(m_addrinfo);
	close(m_socket);
	printf("destructor called\n");
}

/**
 * @brief UDP Sender class (inheritance from UDP base)
 * 
 * @param addr 
 * @param port 
 */
Udp_sender::Udp_sender(const std::string &addr, int port) : Udp_base(addr,port) {

}

/**
 * @brief Send method from UDP Sender class
 * 
 * @param msg 
 * @param size 
 * @return int 
 */
int Udp_sender::send(const char *msg, size_t size) {
	return sendto(m_socket,msg, size, 0, m_addrinfo->ai_addr,m_addrinfo->ai_addrlen);
}

/**
 * @brief UDP Receiver class (inheritance from UDP base)
 * 
 * @param addr 
 * @param port 
 */
Udp_receiver::Udp_receiver(const std::string &addr, int port) : Udp_base(addr,port) {

	int binding = bind(m_socket, m_addrinfo->ai_addr, m_addrinfo->ai_addrlen);
	if(binding != 0) {
		freeaddrinfo(m_addrinfo);
		close(m_socket);
		perror("could not bind");
	}
}

/**
 * @brief Receive method from UDP Receiver class
 * 
 * @param msg 
 * @param size 
 * @return int 
 */
int Udp_receiver::receive(char *msg, size_t size) {
	return recv(m_socket, msg, size, 0);
}
