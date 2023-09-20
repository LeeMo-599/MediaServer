
#ifndef BXC_HLSSERVER_CONNECTION_H
#define BXC_HLSSERVER_CONNECTION_H

#include <vector>
#include <mutex>
#include <queue>

class Connection {
public:
	Connection(int clientFd);
	~Connection();
public:
	int start();
private:
	
	int mClientFd;

};


#endif // BXC_HLSSERVER_CONNECTION_H
