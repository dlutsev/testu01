#include "smultin.h"
#include "ufile.h"
#include "unif01.h"
#include "snpair.h"
#include "swalk.h"
#include "sstring.h"
#include "scomp.h"

int main (void){
unif01_Gen *final;
final = ufile_CreateReadBin("random_data.bin", 2048);
swalk_RandomWalk1(final, NULL, 1, 375000, 0, 32, 128, 128);
ufile_InitReadBin();
swalk_RandomWalk1(final, NULL, 1, 15625*3, 0, 32, 1024, 1024);
ufile_InitReadBin();
swalk_RandomWalk1(final, NULL, 1, 1597*3, 0, 32, 10016, 10016);
ufile_InitReadBin();
sstring_HammingCorr(final, NULL, 1, 375000, 0, 32, 128);
ufile_InitReadBin();
smultin_MultinomialBitsOver(final, NULL, NULL, 2, 3*8000000, 0, 32, 38, TRUE);
ufile_DeleteReadBin(final); 
return 0;
}