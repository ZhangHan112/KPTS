#include "KPTS.h"

int main(int argc,char** argv){
    int Iteration = atoi(argv[1]);
    int Files = atoi(argv[2]);

    KPTS ts(Iteration,Files);
    ts.TS();
    return 0;
}