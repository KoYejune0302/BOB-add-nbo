#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t read_file(const char* filename){
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file\n");

        fclose(file);
        return 0;
    }

    fseek(file, 0, SEEK_END);
    if(ftell(file) != 4){
        printf("File must be exactly 4 bytes long\n");

        fclose(file);
        return 0;
    }
    fseek(file, 0, SEEK_SET);

    uint32_t n;
    fread(&n, 4, 1, file);
    fclose(file);

    return ntohl(n);
}

int main(int argc, char** argv){
    if(argc != 3){
        printf("Wrong number of arguments\n");
        return 1;
    }
    
    uint32_t n1 = read_file(argv[1]);
    uint32_t n2 = read_file(argv[2]);
    
    uint32_t sum = n1 + n2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, sum, sum);

    return 0;   
}