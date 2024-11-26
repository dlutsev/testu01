#include "stdio.h"
#include "stdlib.h"
#include "unif01.h"
#include "ucarry.h"


int create_lcg(long int number_of_bytes){
  unsigned int byte;
  unif01_Gen *gen;
  gen = ucarry_CreateMWC1616(1337, 228, 1111,1001);
  FILE *file=fopen("mwc.bin", "wb");
  if (file == NULL) {
    printf("Error while openning file.\n");
    return 1;
  }
  for(int i=0; i < (int)number_of_bytes/4; i++){
    byte = gen->GetBits(gen->param, gen->state);
    fwrite(&byte, sizeof(byte), 1, file);
  }
  ucarry_DeleteGen(gen);
  fclose(file);
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc!=2){
    printf("ARGC: %d\n", argc);
    return 1;
  }
  long N = strtol(argv[1], NULL,10);
  if(create_lcg(N)==1)
    return 1;
  return 0;
}