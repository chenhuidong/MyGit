all:
	g++ -lthrift Serv.cpp student_types.cpp student_constants.cpp Serv_server.skeleton.cpp -o server
	g++ -lthrift -lm -pthread -lz -lrt -lssl Serv.cpp student_types.cpp student_constants.cpp client.cpp -o client
clean:
	rm *.o server client
#thrift -r --gen cpp student.thrift