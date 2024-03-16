all: app

app: main.o temp_api.o report.o
	gcc -o app main.o temp_api.o report.o

main.o: main.c temp_api.h
	gcc -c -o main.o main.c

report.o: report.c temp_api.h
	gcc -c -o report.o report.c

temp_api.o: temp_api.c
	gcc -c -o temp_api.o temp_api.c

clean:
	rm -f *.o app
