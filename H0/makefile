OUTPUT=bin
ADT=hello
MAIN=hellotest
compile-test: $(MAIN).cpp $(ADT).o
g++ -o $(MAIN) $(MAIN).cpp $(ADT).o
$(ADT).o: $(ADT).cpp $(ADT).h
g++ -c $(ADT).cpp
grade: $(MAIN)
./$(MAIN)