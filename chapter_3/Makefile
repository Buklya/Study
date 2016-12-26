student_info.o: student_info.cpp
	g++ -c -o student_info.o student_info.cpp
median.o: median.cpp
	g++ -c -o median.o median.cpp	
grade.o: grade.cpp
	g++ -c -o grade.o grade.cpp	
main.o: main.cpp
	g++ -c -o main.o main.cpp	
main: student_info.o median.o grade.o main.o
	g++ -o main student_info.o median.o main grade.o main.o