/* 
 * CS:APP Data Lab 
 * 
 * <Anton Belov S23066788>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */
#include <stdio.h>

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */




#endif

int bitXor(int x, int y);
int tmin(void);
int isTmax(int x);
int allOddBits(int x);
int negate(int x);
int isAsciiDigit(int x);
int conditional(int x, int y, int z);
int isLessOrEqual(int x, int y);
int logicalNeg(int x);
int howManyBits(int x);
unsigned floatScale2(unsigned uf);
int floatFloat2Int(unsigned uf);
unsigned floatPower2(int x);


int main() {
  printf("bitXor(4, 5) = %d\n", bitXor(4, 5));
  printf("tmin() = %d\n", tmin());
  printf("isTmax(0x7FFFFFFF) = %d\n", isTmax(0x7FFFFFFF));
  printf("allOddBits(0xAAAAAAAA) = %d\n", allOddBits(0xAAAAAAAA));
  printf("negate(10) = %d\n", negate(10));

  printf("isAsciiDigit(0x35) = %d\n", isAsciiDigit(0x35)); 
  printf("conditional(1, 42, 99) = %d\n", conditional(1, 42, 99)); 
  printf("isLessOrEqual(4, 5) = %d\n", isLessOrEqual(4, 5)); 
  printf("logicalNeg(3) = %d\n", logicalNeg(3)); 
  printf("logicalNeg(0) = %d\n", logicalNeg(0));
  printf("howManyBits(-5) = %d\n", howManyBits(-5)); 
  
  printf("floatScale2(0x3F800000) = 0x%X\n", floatScale2(0x3F800000)); 
  printf("floatFloat2Int(0x41200000) = %d\n", floatFloat2Int(0x41200000)); 
  printf("floatPower2(3) = 0x%X\n", floatPower2(3)); 

  return 0;
}


// 1. bitXor - реализуем XOR через ~ и &
// XOR можно выразить как (A OR B) AND NOT (A AND B)
// Эквивалент через операции ~ и &:
int bitXor(int x, int y) {
  // Используем законы Де Моргана:
  // x ^ y = (~x & y) | (x & ~y)
  // Эквивалентное представление через ~ и &:
  return ~(~x & ~y) & ~(x & y);
//   ~ — побитовая инверсия (заменяет 1 на 0 и наоборот)

//   & — побитовое И (AND)

//   | — побитовое ИЛИ (OR), но мы его не используем напрямую
}

// 2. tmin - минимальное число в 32-битном 2-комплементарном представлении
// Минимальное число равно 1 << 31 (10000000 00000000 00000000 00000000)
int tmin(void) {
  return 1 << 31;
}

//1 << 31 — сдвиг 1 на 31 бит влево
// Получаем 0x80000000, что есть минимальное число в int
// в 2-ух комплементарном коде (двойном дополнении): -2147483648

// 3. isTmax - проверка, является ли x максимальным числом в 32-битном представлении
// Tmax = 0x7FFFFFFF (01111111 11111111 11111111 11111111)
// Проверяем, что x + 1 дает инверсию x, но x != -1 (0xFFFFFFFF)
int isTmax(int x) {
  return !(~(x + 1) ^ x) & !!(x + 1);
}
// ~ — инверсия
// ^ — XOR
// ! — логическое НЕ
// & — логическое И
// !! — превращает в 0 или 1
// Смысл: Проверить, что
// ~(x + 1) == x ⟺ x == 0x7FFFFFFF
// исключить x = -1 (особый случай)

// 4. allOddBits - проверка, установлены ли все нечетные биты в 1
// Создаем маску 0xAAAAAAAA (10101010... в 32-битном представлении)
// Проверяем, что x & mask == mask
int allOddBits(int x) {
  int mask = 0xAA + (0xAA << 8) + (0xAA << 16) + (0xAA << 24);
  return !((x & mask) ^ mask);
}

// 0xAA = 10101010 — шаблон нечетных бит

// mask — собираем полный 32-битный шаблон 0xAAAAAAAA

// Проверяем:
// Если (x & mask) == mask, значит все нечетные биты в x установлены в 1

// 5. negate - возвращает -x
// Используем свойство двухкомплементарного представления: -x = ~x + 1
int negate(int x) {
  return ~x + 1;
}

// Это классическая формула получения отрицательного числа в 2-комплементарном виде.
// −x=∼x+1

// 6. isAsciiDigit - проверяет, находится ли число в диапазоне ASCII-цифр (0x30 - 0x39)
// Проверяем, что x >= 0x30 и x <= 0x39 с использованием битовых операций
int isAsciiDigit(int x) {
  // Проверяем x - 0x30 >= 0 и x - 0x3A < 0
  return !((x + ~0x30 + 1) >> 31) & ((x + ~0x3A + 1) >> 31);
}

// Проверка:

// x >= 0x30 (код '0')

// x <= 0x39 (код '9')

// Трюк:

// x - 0x30 >= 0 → сдвиг вправо покажет 0, иначе 1

// x - 0x3A < 0 → аналогично


// 7. conditional - эквивалент x ? y : z
// Создаем маску, которая будет либо 0xFFFFFFFF (если x != 0), либо 0x00000000 (если x == 0)
int conditional(int x, int y, int z) {
  int mask = ~(!x) + 1;
  return (mask & y) | (~mask & z);
}

// Создаем:

// mask = 0xFFFFFFFF, если x != 0

// mask = 0x00000000, если x == 0

// Получаем:

// Если x != 0 вернётся y

// Если x == 0 вернётся z

// 8. isLessOrEqual - проверка x <= y
// Вычисляем разницу y - x и проверяем знак результата
int isLessOrEqual(int x, int y) {
  int diff = y + ~x + 1;
  return !(diff >> 31);
}

// Смысл:

// (y - x >= 0) — значит x <= y

// diff = y - x

// diff >> 31 покажет 1, если diff < 0

// ! инвертирует

// 9. logicalNeg - реализация логического отрицания (!x) без использования !
// Используем свойство: (x | -x) дает 0 только для x = 0
int logicalNeg(int x) {
  return ((x | (~x + 1)) >> 31) + 1;
}

// Фишка:

// Только для x=0 будет (x | -x) == 0

// >> 31 даст 0, значит +1 вернёт 1 (то есть !0 = 1)

// Для остальных даст 0



// 10. howManyBits - минимальное количество бит для представления x
// Ищем позицию самого значимого бита (используем поразрядное деление на группы)
int howManyBits(int x) {
  int bit16, bit8, bit4, bit2, bit1, bit0;
  x ^= (x >> 31); // Если x отрицательное, инвертируем
  bit16 = !!(x >> 16) << 4;
  x >>= bit16;
  bit8 = !!(x >> 8) << 3;
  x >>= bit8;
  bit4 = !!(x >> 4) << 2;
  x >>= bit4;
  bit2 = !!(x >> 2) << 1;
  x >>= bit2;
  bit1 = !!(x >> 1);
  x >>= bit1;
  bit0 = x;
  return bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1;
}

// Сначала x ^= (x >> 31) инвертирует x, если он отрицательный

// После этого ищем позицию самого старшего бита (MSB)

// Суммируем найденные позиции битов

// +1 — для учета знакового бита

// 11. floatScale2 - удваивает значение float
// Если число - NaN или бесконечность, возвращаем его же
unsigned floatScale2(unsigned uf) {
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned sign = uf & (1 << 31);
  if (exp == 0xFF) return uf; // Если NaN или бесконечность, возвращаем без изменений
  if (!exp) return (uf << 1) | sign; // Для денормализованных чисел сдвигаем мантиссу
  return ((exp + 1) << 23) | (uf & 0x807FFFFF); // Увеличиваем экспоненту
}

// Выделяем exp (экспоненту) и sign (знак)

// Если exp == 0xFF — это NaN или бесконечность → вернём как есть

// Если exp == 0 — денормализованное число → просто сдвигаем мантиссу

// Если обычное число → увеличиваем exp на 1



// 12. floatFloat2Int - конвертация float в int
// Извлекаем знак, экспоненту и мантиссу, проверяем граничные случаи
int floatFloat2Int(unsigned uf) {
  unsigned sign = uf >> 31;
  int exp = ((uf >> 23) & 0xFF) - 127;
  unsigned frac = (uf & 0x7FFFFF) | 0x800000;
  if (exp < 0) return 0; // Если экспонента меньше 0, округляем к 0
  if (exp > 31) return 0x80000000; // Если слишком большое число, возвращаем переполнение
  if (exp > 23) frac <<= (exp - 23);
  else frac >>= (23 - exp);
  return sign ? -frac : frac;
}

// sign — знак

// exp — реальная экспонента

// frac — нормализованная мантисса

// Если:

// exp < 0 → дробь < 1 → округляем в 0

// exp > 31 → переполнение

// Иначе переводим дробь в целое, учитывая знак

// 13. floatPower2 - вычисляет 2^x в представлении float
// Проверяем на выход за границы float
unsigned floatPower2(int x) {
  if (x < -126) return 0; // Если x слишком маленькое, возвращаем 0
  if (x > 127) return 0x7F800000; // Если x слишком большое, возвращаем бесконечность
  return (x + 127) << 23; // Кодируем экспоненту
}

// Смысл:

// Если x < -126 — слишком маленькое, возвращаем 0

// Если x > 127 — переполнение → +∞

// Иначе просто кодируем exp = x + 127 в поле экспоненты