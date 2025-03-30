###### Problem 0x1 solutions
Perform the following number conversions:
* `0x21e1ed30` to binary: `00100001111000011110110100110000`
* `01000110001110101110101011010111` to hexadecimal: `0x463aead7`
* `0x19b4792d` to binary: `00011001101101000111100100101101`
* `00110011110110010110110011001010` to hexadecimal: `0x33d96cca`

###### Problem 0x2 solutions
What numbers do the following bit-vectors encode in 8-bit two's complement encoding:
* `01111001` to two's complement: `121`
* `00000010` to two's complement: `2`
* `00010001` to two's complement: `17`
* `00010001` to two's complement: `17`

###### Problem 0x3 solutions
Find additive inverse of the following 8-bit unsigned numbers:
* `121` : `135` 
* `  2` : `254` 
* ` 17` : `239` 
* ` 17` : `239` 

###### Problem 0x4 solutions
Find the binary representation of the negatives of each of the following 8-bit numbers in two's complements encoding:
* ` 69 : T2B( -69) = 10111011`
* ` 44 : T2B( -44) = 11010100`
* ` 56 : T2B( -56) = 11001000`
* ` 19 : T2B( -19) = 11101101`

###### Problem 0x5
Implement multiplication of an integer `x` by the the following constants `k` using only addition, subtraction and shift operations using as minimum operations as possible.
* `k =  71` : `kx = x<<6 + x<<2 + x<<1 + x`
* `k =  46` : `kx = x<<5 + x<<3 + x<<2 + x<<1`
* `k = 185` : `kx = x<<7 + x<<5 + x<<4 + x<<3 + x`
* `k =  21` : `kx = x<<4 + x<<2 + x`

###### Problem 0x6
Which `float` number is encoded by the following hexadecimals:
* `0x42f34000` : `121.625`
* `0xc18a0000` : `-17.250`
* `0x409c0000` : `4.875`
* `0xc2b54000` : `-90.625`

###### Problem 0x7
Write the hexadecimal representations of the following  `float` numbers:
* $+0.0$
* $+\infty$
* $0.5\times2^{-126}$ (in denormalized way)
* $2^{-126}$ (in denormalized way)
* $2^{-126}$ (in normalized way)

###### Problem 0x8
For each of the following lines of assembly language, determine the appropriate instruction suffix based on the operands. (For example, `mov` can be rewritten as `movb`, `movw`, `movl`, or `movq`.)
* `movl %edi (%ecx,%esp)
* `movq %rdx (%r8)
* `movl (%eax) %r12d
* `movq $0x4f %rsp
* `movl (%edx,%r12d,1) %edi

