Name: Dylan Droll
EID: DJD2554
Email: dylan.droll@gmail.com

AES encryption begins with a key expansion, taking a provided key and creating numerous round keys.
The first round key is the provided key and each subsequent key is created by preforming transformations
on the previous 32 bit words. The previous word is left shifted once and the first character is cycled
to the back. Then the bytes of the word are substituted with their respective entries in the S-box, mirroring
a future step in the process. Finally the first byte in the word has bitwise exclusive or performed on it
with a value from the rcon array. These steps are performed until all the round keys have been created.

Once round keys have been generated, the main loop of the algorithm is invoked. 16 byte blocks are encrypted
by first performing bitwise exclusive or with the first round key bytes. Next, each byte of the block is replaced
by its corresponding byte in the S-Box. Next, the block of 16 bytes, arranged as you can see below and to
the left, has each of its horizontal rows shifted to the left a number of times equal to their position in the
block. Therefore the top is shifted 0 times, the row below is shifted left once, etc. This produces 16 byte block
as seen to the below and to the right. 

00 04 08 12    00 04 08 12
01 05 09 13 -> 05 09 13 01
02 06 10 14    10 14 02 06
03 07 11 15    15 03 07 11

The final step in the main loop is mix columns step. Each column is matrix multipied by a set Galois 
multiplication array. After the main loop has concluded, the block is transformed one final time by having
its bytes substituted, its row shifted, and the final round key added to the block. For decryption, the algorithm 
does the inverse operation of the previously executed steps in reverse order of the encryption process. 
