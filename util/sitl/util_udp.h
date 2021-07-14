#ifndef UTIL_UDP_H
#define UTIL_UDP_H

#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>




class Udp_base {

public:

	Udp_base(const std::string &addr, int port);
	~Udp_base();

	int get_socket() const;
	int get_port() const;
	std::string get_addr() const;

	
	int m_socket;
	int m_port;
	std::string m_addr;
	struct addrinfo *m_addrinfo;
};

class Udp_sender : public Udp_base {

public:
	Udp_sender(const std::string &addr, int port);
	int send(const char *msg, size_t size);
};

class Udp_receiver : public Udp_base {

public:

	Udp_receiver(const std::string &addr, int port);
	int receive(char *msg, size_t size);
};


#endif