singleton:
  main.o singleton.o
    gcc main.o singleton.o -o singleton

file1.o:main.c singleton.h singletonA.h singletonB.h
    gcc -c main.c -o main.o

file2.o:singleton.c singleton.h singletonA.h singletonB.h
    gcc -c singleton.c -o singleton.o

clean:
    rm -rf *.o singleton
