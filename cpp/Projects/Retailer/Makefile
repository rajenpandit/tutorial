
CXXFLAGS= -std=c++11
# Target : Dependency

Retailer : Main.o Product.o Customer.o
	g++ ${CXXFLAGS} Main.o Product.o Customer.o -o Retailer

Main.o : Main.cpp
	g++ ${CXXFLAGS} -c Main.cpp
Product.o : Product.cpp
	g++ ${CXXFLAGS} -c Product.cpp
Customer.o : Customer.cpp
	g++ ${CXXFLAGS} -c Customer.cpp