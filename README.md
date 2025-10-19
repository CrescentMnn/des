# Data Encryption Standard

The Data Encryption Standard is a *symmetrical* encryption implementation, consisting of a key of 56 bits and a 64 bit plaintext block which is going to be encrypted, it was developed in 1970 at IBM.

DES is now considered depreciated since its 56 bit key is considered to be relatively short, thus making this an insecure way of encrypting data.


## How DES works

DES can be divided in the two most important parts of the algorithm, *key schedule* and *encryption rounds*, this is how my programs workflow is going to be divided.

### Key Schedule

The DES key scheudle is what defines our initial key and the subsequent round keys, as it works by having a 64-bit input key, and applying a PC1 operation on it, this PC1 operation changes the bit values according to a specified table, leaving out the 8, 16, 24, 32 and 64 bits, these are considered parity bits and are use to check for errors in the key. This means our 64 bit key is taken down into a 56 bit value (which corresponds to our 56 bit key as specified before).

*The output of our PC1 operation is what the defines our initial key, as this is the base for the following procedures.*

The first operation in the key schedule is a *left shift* operation, which works by performing a left shift of *n* on every round, where *n* is dictated by the table depicted in *figure 1*

### Encryption Rounds
