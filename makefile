CXXFLAG += -std=c++11

cc = g++
objects = epoll_demultiplexer.o listen_handler.o reactor.o reactor_impl.o socket_handler.o
exe = reactor_server

${exe}:${objects}
	${cc} ${objects} ${CXXFLAG} server.cpp -o ${exe}
	${cc} client.cpp -o reactor_client

listen_handler.o:
	${cc} -c listen_handler.cpp ${CXXFLAG} 

reactor.o:
	${cc} -c reactor.cpp ${CXXFLAG} 

reactor_impl.o:
	${cc} -c reactor_impl.cpp ${CXXFLAG} 

socket_handler.o:
	${cc} -c socket_handler.cpp ${CXXFLAG} 

epoll_demultiplexer.o:
	${cc} -c epoll_demultiplexer.cpp ${CXXFLAG} 

client: client.cpp
	g++ client.cpp -o reactor_client

.PHONY:clean
clean:
	rm ${exe} ${objects}
