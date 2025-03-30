###### Problem 0x1 solutions
Perform the following number conversions:
* `0x21e1ed30` to binary: `00100001111000011110110100110000`
* `01000110001110101110101011010111` to hexadecimal: `0x463aead7`
* `0x19b4792d` to binary: `00011001101101000111100100101101`
* `00110011110110010110110011001010` to hexadecimal: `0x33d96cca`

###### Problem 0x2 solutions
What numbers do the following bit-vectors encode in 8-bit two's complement encoding:
* `00110000` to two's complement: `48`
* `11010111` to two's complement: `-41`
* `00101101` to two's complement: `45`
* `11001010` to two's complement: `-54`

###### Problem 0x3 solutions
Find additive inverse of the following 8-bit unsigned numbers:
* ` 48` : `208` 
* `215` : ` 41` 
* ` 45` : `211` 
* `202` : ` 54` 

###### Problem 0x4 solutions
Find the binary representation of the negatives of each of the following 8-bit numbers in two's complements encoding:
* ` 35 : T2B( -35) = 11011101`
* ` 78 : T2B( -78) = 10110010`
* ` 64 : T2B( -64) = 11000000`
* ` 43 : T2B( -43) = 11010101`

###### Problem 0x5
Implement multiplication of an integer `x` by the the following constants `k` using only addition, subtraction and shift operations using as minimum operations as possible.
* `k = 164` : `kx = x<<7 + x<<5 + x<<2`
* `k = 207` : `kx = x<<7 + x<<6 + x<<3 + x<<2 + x<<1 + x`
* `k = 193` : `kx = x<<7 + x<<6 + x`
* `k = 172` : `kx = x<<7 + x<<5 + x<<3 + x<<2`

###### Problem 0x6
Which `float` number is encoded by the following hexadecimals:
* `0x42408000` : `48.125`
* `0xc2378000` : `-45.875`
* `0x42fb4000` : `125.625`
* `0xc2f38000` : `-121.750`

###### Problem 0x7
Write the hexadecimal representations of the following  `float` numbers:
* $+0.0$
* $+\infty$
* $0.5\times2^{-126}$ (in denormalized way)
* $2^{-126}$ (in denormalized way)
* $2^{-126}$ (in normalized way)

###### Problem 0x8
For each of the following lines of assembly language, determine the appropriate instruction suffix based on the operands. (For example, `mov` can be rewritten as `movb`, `movw`, `movl`, or `movq`.)
* `movq %rsi (%rdx,%rsp)
* `movl %eax (%r12d)
* `movq (%rbx) %rdi
* `movl $0x67 %r8d
* `movl (%eax,%r8d,8) %esi

