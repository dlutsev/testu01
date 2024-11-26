#include "stdio.h"
#include "stdlib.h"
#include "unif01.h"
#include "ulcg.h"
#include "ulec.h"

int crrate_cubic(long int number_of_bytes){
  unsigned int byte;
  unif01_Gen *gen;
  gen = ulec_CreateMRG32k3a(12345.0,4321.0,376.0,12345.0,940.0,123.0);
  FILE *file=fopen("mrg.bin", "wb");
  if (file == NULL) {
    printf("Error while openning file.\n");
    return 1;
  }
  for(int i=0; i < (int) number_of_bytes/4; i++){
    byte = gen->GetBits(gen->param, gen->state);
    fwrite(&byte, sizeof(byte), 1, file);
  }
  ulec_DeleteGen(gen);
  fclose(file);
  return 0;
}

int create_lcg(long int number_of_bytes){
  unsigned int byte;
  unif01_Gen *gen;
  gen = ulcg_CreateLCG(2147483647, 16807,0,12345);
  FILE *file=fopen("lcg.bin", "wb");
  if (file == NULL) {
    printf("Error while openning file.\n");
    return 1;
  }
  for(int i=0; i < (int)number_of_bytes/4; i++){
    byte = gen->GetBits(gen->param, gen->state);
    fwrite(&byte, sizeof(byte), 1, file);
  }
  ulcg_DeleteGen(gen);
  fclose(file);
  return 0;
}

void create_final(long int number_of_bytes){
  FILE *file1=fopen("mrg.bin", "rb");
  FILE *file2=fopen("lcg.bin", "rb");
  FILE *final=fopen("final.bin", "wb");
  unsigned char byte1, byte2;
  for (int i = 1; i <= (int)number_of_bytes; i++) {
    if (i % 2 == 0) {
        if (fread(&byte2, sizeof(unsigned char), 1, file2) == 1) {
            fwrite(&byte2, sizeof(unsigned char), 1, final);
            fread(&byte1, sizeof(unsigned char), 1,  file1);
        } else {
            printf("Error reading from lcg.bin on position %d\n", i);
            break;
          }
    } else {
        if (fread(&byte1, sizeof(unsigned char), 1, file1) == 1) {
          fwrite(&byte1, sizeof(unsigned char), 1, final);
          fread(&byte2, sizeof(unsigned char), 1,  file2);
        } else {
            printf("Error reading from mrg.bin on position %d\n", i);
            break;
          }
      }
  }
}

int main(int argc, char *argv[]) {
  if (argc!=2){
    printf("ARGC: %d\n", argc);
    return 1;
  }
  long N = strtol(argv[1], NULL,10);
  if(crrate_cubic(N)==1  || create_lcg(N)==1)
    return 1;
  create_final(N);
  return 0;
}