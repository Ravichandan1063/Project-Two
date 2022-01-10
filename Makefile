all: fifth.cpp 
		g++ -g -Wall -o fifth fifth.cpp

	clean: 
		$(RM) fifth