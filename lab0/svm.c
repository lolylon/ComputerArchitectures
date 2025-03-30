#include <stdio.h>

#define READ 10 // reads data from keyboard to memory
#define WRITE 11 // writes data from memory to display
#define LOAD 20 // loads data from memory to accumulator
#define STORE 21 // stores data from accumulator to memory
#define ADD 30 // adds a value from memory to accumulator
#define SUBTRACT 31 // …
#define DIVIDE 32 // …
#define MULTIPLY 33 // …
#define BRANCH  40 // branches to a specific location in memory
#define BRANCHNEG 41 // … if accumulator is negative
#define BRANCHZERO 42 // … if accumulator is zero
#define HALT 43 // halts the program
#define BRANCHPOS 44 // … if accumulator is pos

// processor
int AC=0;
int PC=0;
int IR=0;
int opcode=0;
int operand=0;

// memory
int RAM[100];

// execution
int main(int argc, char* argv[]){ // argv[] = args[], argc = args.length

    FILE* f = fopen(argv[1],"r");
    
    if (f == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    printf("Simpletron is loading ... \n");
    int n=0;
    int x;
    while (n<100 && fscanf(f,"%d",&x)==1){
        if (x>=-9999 && x<=9999)
            RAM[n++] = x;
        else{
            printf("Wrong machine code ...\n");
            return 1;
        }
    }
    fclose(f);

    printf("Simpletron is executing ...\n");
    
    // // Отладочный вывод содержимого памяти
    // printf("Memory contents:\n");
    // for(int i = 0; i < n; i++) {
    //     printf("%02d: %+05d\n", i, RAM[i]);
    // }
    
    while(PC < 100) {
        IR = RAM[PC++];
        opcode = IR / 100; // 10
        operand = IR % 100; // 07
        
        
        switch(opcode) {
            case READ:
                printf("Enter a number: ");
                scanf("%d",&x);
                if (x > 9999 || x < -9999) {
                    printf("Runtime error (wrong input) ...\n");
                    return 1;
                }
                RAM[operand] = x;
                // printf("Value %d stored at address %d\n", x, operand);
                break;
            case WRITE:
                printf("Value at address %d: %d\n", operand, RAM[operand]);
                break;
            case LOAD:
                AC = RAM[operand];
                // printf("Loaded %d into accumulator\n", AC);
                break;
            case STORE:
                RAM[operand] = AC;
                // printf("Stored accumulator value %d at address %d\n", AC, operand);
                break;
            case ADD:
                AC += RAM[operand];
                break;
            case SUBTRACT:
                AC -= RAM[operand];
                break;
            case MULTIPLY:
                AC *= RAM[operand];
                break;
            case DIVIDE:
                AC /= RAM[operand];
                break;
            case BRANCH:
                PC = operand;
                break;
            case BRANCHNEG:
                if (AC < 0) PC = operand;
                break;
            case BRANCHZERO:
                if (AC == 0) PC = operand;
                break;
            case HALT:
                printf("Simpletron execution terminated ...\n");
                return 0;
                break;
            default:
                printf("Runtime error (wrong operation) ...\n");
                return 1;
        }
    }
    return 0;
}