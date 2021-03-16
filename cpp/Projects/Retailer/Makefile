
CXXFLAGS= -std=c++11
# Target : Dependency

Retailer : Main.o Product.o
	g++ ${CXXFLAGS} Main.o Product.o -o Retailer

Main.o : Main.cpp
	g++ ${CXXFLAGS} -c Main.cpp
Product.o : Product.cpp
	g++ ${CXXFLAGS} -c Product.cpp