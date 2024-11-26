#include "smultin.h"
#include "ufile.h"
#include "unif01.h"
#include "snpair.h"
#include "swalk.h"
#include "sstring.h"


int main (void){
unif01_Gen *final;
final = ufile_CreateReadBin("final.bin", 2048);
swalk_RandomWalk1(final, NULL, 1, 375000, 0, 32, 128, 128);
ufile_InitReadBin();
snpair_ClosePairsBitMatch(final, NULL, 1, 750000, 0, 2);
ufile_InitReadBin();
swalk_RandomWalk1(final, NULL, 1, 46875, 0, 32, 1024, 1024);
ufile_InitReadBin();
sstring_HammingWeight(final, NULL, 1, 1500000, 0, 32, 32);
ufile_InitReadBin();
sstring_HammingCorr(final, NULL, 1, 750000, 0, 32, 64);
ufile_DeleteReadBin(final);
return 0;
}