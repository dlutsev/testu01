#include "smultin.h"
#include "ufile.h"
#include "unif01.h"
#include "snpair.h"
#include "swalk.h"
#include "sstring.h"


int main (void){
unif01_Gen *final;
final = ufile_CreateReadBin("final.bin", 2048);
swalk_RandomWalk1(final, NULL, 1, 150000, 0, 32, 320, 320);
ufile_InitReadBin();
smultin_MultinomialBitsOver(final, NULL, NULL, 1, 3*16000000,0, 32, 4, 0);
ufile_InitReadBin();
smultin_MultinomialBitsOver(final, NULL, NULL, 1, 3*16000000,0, 32, 8, 0);
ufile_InitReadBin();
sstring_HammingIndep(final, NULL, 1, 1500000, 0, 32, 16, 0);
ufile_InitReadBin();
sstring_HammingIndep(final, NULL, 1, 750000, 0, 32, 32, 0);
ufile_DeleteReadBin(final);
return 0;
}