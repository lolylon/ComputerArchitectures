#include <stdio.h>
#include <string.h>

// Определяем числовые коды для каждой инструкции
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43
#define BRANCHPOS 44

// Структура для хранения переменных и их адресов
typedef struct {
    char name;   // Имя переменной (например, 'A', 'B', 'C')
    int address; // Адрес переменной в памяти
} Variable;

Variable vars[10]; // Массив для хранения переменных (до 10 переменных)
int var_count = 0; // Количество объявленных переменных

// Функция для получения адреса переменной (если нет — создаем новую)
int get_var_address(char var) {
    for (int i = 0; i < var_count; i++) {
        if (vars[i].name == var) return vars[i].address; // Если переменная уже есть, вернуть её адрес
    }
    // Если переменная новая, добавляем её в массив
    vars[var_count].name = var;
    vars[var_count].address = 90 + var_count; // Адреса начинаются с 90 (вместо 7)
    return vars[var_count++].address; // Возвращаем адрес и увеличиваем счётчик переменных
}

// Функция для получения числового кода инструкции по её названию
int get_opcode(const char *instr) {
    if (strcmp(instr, "READ") == 0) return READ;
    if (strcmp(instr, "WRITE") == 0) return WRITE;
    if (strcmp(instr, "LOAD") == 0) return LOAD;
    if (strcmp(instr, "STORE") == 0) return STORE;
    if (strcmp(instr, "ADD") == 0) return ADD;
    if (strcmp(instr, "SUBTRACT") == 0) return SUBTRACT;
    if (strcmp(instr, "DIVIDE") == 0) return DIVIDE;
    if (strcmp(instr, "MULTIPLY") == 0) return MULTIPLY;
    if (strcmp(instr, "BRANCH") == 0) return BRANCH;
    if (strcmp(instr, "BRANCHNEG") == 0) return BRANCHNEG;
    if (strcmp(instr, "BRANCHZERO") == 0) return BRANCHZERO;
    if (strcmp(instr, "BRANCHPOS") == 0) return BRANCHPOS;
    if (strcmp(instr, "HALT") == 0) return HALT;
    return -1; // Если команда не найдена, вернуть -1
}

int main() {
    // Открываем файлы для чтения и записи
    FILE *input = fopen("fori.txt", "r");  // Файл с исходным кодом
    FILE *output = fopen("output.txt", "w"); // Файл для записи машинного кода

    if (!input || !output) { // Проверка на ошибки открытия файлов
        printf("Error opening file!\n");
        return 1;
    }

    printf("Simpletron assembler is running...\n");

    char instr[20], var; // instr — строка для команды, var — переменная
    while (fscanf(input, "%s", instr) == 1) { // Читаем первую часть команды (инструкцию)
        int opcode = get_opcode(instr); // Получаем числовой код инструкции
        int address = 0; // Адрес переменной, если требуется

        if (opcode == -1) { // Если команда не найдена, значит, это объявление переменной
            get_var_address(instr[0]); // Добавляем переменную в список
            continue; // Переходим к следующей строке
        }

        if (opcode != HALT) { // Если команда не HALT, должна быть переменная
            fscanf(input, " %c", &var); // Читаем имя переменной
            address = get_var_address(var); // Получаем или создаем её адрес
        }

        // Записываем команду в файл в формате "операция + адрес" (например, 1007)
        fprintf(output, "%d%02d\n", opcode, address);
    }

    // Записываем нули для всех переменных в конец файла
    for (int i = 0; i < var_count; i++) {
        fprintf(output, "0\n");
    }

    // Закрываем файлы
    fclose(input);
    fclose(output);
    printf("Assembly completed! Output written to 'output.txt'\n");

    return 0;
}