#include "smultin.h"
#include "ufile.h"
#include "unif01.h"
#include "snpair.h"
#include "swalk.h"
#include "sstring.h"
#include "scomp.h"

int main (void){
unif01_Gen *final;
final = ufile_CreateReadBin("final.bin", 2048);
swalk_RandomWalk1(final, NULL, 1, 375000, 0, 32, 128, 128);
ufile_InitReadBin();
scomp_LempelZiv(final, NULL, 1, 23, 0, 32);
ufile_InitReadBin();
sstring_HammingCorr(final, NULL, 1, 750000, 0, 32, 64);
sstring_LongestHeadRun(final, NULL, 1, 60, 0, 32, 266656);
ufile_InitReadBin();
sstring_HammingIndep(final, NULL, 1, 750000, 0, 32, 32, 0);
ufile_DeleteReadBin(final); 
return 0;
}