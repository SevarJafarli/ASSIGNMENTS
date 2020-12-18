lab: lab.o binary_sum.o
    gcc -o lab lab.o binary_sum.o

lab.o: lab.c binary_sum.h
    gcc -c lab.c

binary_sum.o: binary_sum.c binary_sum.h
    gcc -c binary_sum.c

clean:
    rm lab.exe lab.o binary_sum.o
