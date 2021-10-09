OBJS = main.o haha.o sin_value.o cos_value.o
main: ${OBJS}
	gcc -o $@ ${OBJS} -lm
%.o: %.c
	gcc -o $@ -c $^
clean:
	rm -f main ${OBJS}