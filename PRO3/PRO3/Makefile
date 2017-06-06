CXX = g++ -std=c++11 -c
CFLAGS = -Wall
SOURCES = helper.o 2OPT.o nearestNeighbor.o InAndOut.o christofides.o
HEADERS = helper.hpp 2OPT.hpp nearestNeighbor.hpp InAndOut.hpp cityData.hpp christofides.hpp

main: ${SOURCES} ${HEADERS}
	g++ -std=c++11 -o main main.cpp ${SOURCES} -Wall -lm

nearestNeighbor.o: nearestNeighbor.cpp nearestNeighbor.hpp cityData.hpp
	${CXX} nearestNeighbor.cpp ${CFLAGS}

helper.o: helper.cpp helper.hpp cityData.hpp
	${CXX} helper.cpp ${CFLAGS}

InAndOut.o: InAndOut.cpp InAndOut.hpp cityData.hpp
	${CXX} InAndOut.cpp ${CFLAGS}

2OPT.o: 2OPT.cpp 2OPT.hpp cityData.hpp
	${CXX} 2OPT.cpp ${CFLAGS}

christofides.o: christofides.cpp christofides.hpp cityData.hpp
	${CXX} christofides.cpp ${CFLAGS}

clean:
	rm -f *.o main results.txt runtime.txt
