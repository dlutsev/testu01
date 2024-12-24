#include "smultin.h"
#include "ufile.h"
#include "swalk.h"


int main (void){
unif01_Gen *final;
final = ufile_CreateReadBin("random_data.bin", 2048);
swalk_RandomWalk1(final, NULL, 1, 20*125000, 0, 32, 128, 128);
ufile_DeleteReadBin(final);
return 0;
}