###### Problem 0x1 solutions
Perform the following number conversions:
* `0x3dd6f55b` to binary: `00111101110101101111010101011011`
* `01110000011101100111001111110100` to hexadecimal: `0x707673f4`
* `0x279398f0` to binary: `00100111100100111001100011110000`
* `00000110000010101110010001111010` to hexadecimal: `0x060ae47a`

###### Problem 0x2 solutions
What numbers do the following bit-vectors encode in 8-bit two's complement encoding:
* `01011011` to two's complement: `91`
* `11110100` to two's complement: `-12`
* `11110000` to two's complement: `-16`
* `01111010` to two's complement: `122`

###### Problem 0x3 solutions
Find additive inverse of the following 8-bit unsigned numbers:
* ` 91` : `165` 
* `244` : ` 12` 
* `240` : ` 16` 
* `122` : `134` 

###### Problem 0x4 solutions
Find the binary representation of the negatives of each of the following 8-bit numbers in two's complements encoding:
* ` 20 : T2B( -20) = 11101100`
* ` 64 : T2B( -64) = 11000000`
* ` 47 : T2B( -47) = 11010001`
* ` 31 : T2B( -31) = 11100001`

###### Problem 0x5
Implement multiplication of an integer `x` by the the following constants `k` using only addition, subtraction and shift operations using as minimum operations as possible.
* `k = 149` : `kx = x<<7 + x<<4 + x<<2 + x`
* `k =  66` : `kx = x<<6 + x<<1`
* `k = 176` : `kx = x<<7 + x<<5 + x<<4`
* `k = 160` : `kx = x<<7 + x<<5`

###### Problem 0x6
Which `float` number is encoded by the following hexadecimals:
* `0x42b6c000` : `91.375`
* `0xc3708000` : `-240.500`
* `0x42e64000` : `115.125`
* `0xc0680000` : `-3.625`

###### Problem 0x7
Write the hexadecimal representations of the following  `float` numbers:
* $+0.0$
* $+\infty$
* $0.5\times2^{-126}$ (in denormalized way)
* $2^{-126}$ (in denormalized way)
* $2^{-126}$ (in normalized way)

###### Problem 0x8
For each of the following lines of assembly language, determine the appropriate instruction suffix based on the operands. (For example, `mov` can be rewritten as `movb`, `movw`, `movl`, or `movq`.)
* `movb %sil (%al,%bpl)
* `movb %cl (%dil)
* `movq (%rcx) %r12
* `movq $0xdc %r8
* `movl (%edx,%r12d,2) %edi

