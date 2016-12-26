TARGET = task_5_0

.PHONY: all clean
all: $(TARGET)
clean:
	DEL | ERASE $(TARGET) *.o
extract_fails.o: extract_fails.cpp
	g++ -c -o extract_fails.o extract_fails.cpp
student_info.o: student_info.cpp
	g++ -c -o student_info.o student_info.cpp
median.o: median.cpp
	g++ -c -o median.o median.cpp	
grade.o: grade.cpp
	g++ -c -o grade.o grade.cpp	
main.o: main.cpp
	g++ -c -o main.o main.cpp	
$(TARGET): extract_fails.o student_info.o median.o grade.o main.o
	g++ -o $(TARGET) extract_fails.o student_info.o median.o grade.o main.o