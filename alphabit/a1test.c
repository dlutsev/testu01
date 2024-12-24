#include "smultin.h"
#include "ufile.h"
#include "swalk.h"


int main (void){
unif01_Gen *final;
final = ufile_CreateReadBin("final.bin", 2048);
swalk_RandomWalk1(final, NULL, 1, 50000*20, 0, 32, 320, 320);
ufile_DeleteReadBin(final);
return 0;
}