// objdump -d mstore.o

long mult2(long x, long y);

void multstroe(long x, long y, long* des){
    long t = mult2(x, y);
    *des = t;
}