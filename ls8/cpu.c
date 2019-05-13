#include "cpu.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * Load the binary bytes from a .ls8 source file into a RAM array
 */
/**
 * Initialize a CPU struct
 */
void cpu_init(struct cpu *cpu)
{
  // TODO: Initialize the PC and other special registers
  cpu->PC = 0;
  memset(cpu->registers, 0, sizeof(cpu->registers));
  memset(cpu->ram, 0, sizeof(cpu->ram));
}
unsigned char cpu_ram_read(struct cpu *cpu, unsigned char MAR)
{
  return cpu->ram[MAR];
}
void cpu_ram_write(struct cpu *cpu)
{

}
void cpu_load(struct cpu *cpu,int argc, char *argv[])
{
  FILE *fp;
  int index = 0;
  char data[1000];
  char line[256];
  if(!argv[1]){
    puts("ERROR: MISSING FILE TO RUN");
    exit(1);
  }
  fp = fopen(argv[1],"r");
  printf("Reading file %s...\n\n", argv[1]);
  if(fp!=NULL){
    while(fgets(line,sizeof(line),fp)){
      printf("%s\n",line);
      for(int i = 0; i<sizeof(line)
    }
  }
  fclose(fp);
  int address = 0;
  int length = 6;
  // int data[length];
  for (int i = 0; i < length; i++) {
    cpu->ram[address++] = data[i];
  }

  // TODO: Replace this with something less hard-coded
}

/**
 * ALU
 */
void alu(struct cpu *cpu, enum alu_op op, unsigned char regA, unsigned char regB)
{
  switch (op) {
    case ADD:
      // TODO
      break;
    // TODO: implement more ALU ops
  }
}

/**
 * Run the CPU
 */
void cpu_run(struct cpu *cpu)
{
  int running = 1;
  unsigned char command, operandA,operandB;
  while (running) {
    command = cpu_ram_read(cpu, cpu->PC);
    operandA = cpu_ram_read(cpu, cpu->PC + 1);
    operandB = cpu_ram_read(cpu, cpu->PC + 2);
    switch(command)
    {
      case HLT:
        running = 0;
        cpu->PC +=1;
        break;
      case LDI:
        cpu->registers[operandA] = operandB;
        break;
      case PRN:
        printf("%d\n", cpu->registers[operandA]);
        break;
    }
    cpu->PC += 1;
  }
}

