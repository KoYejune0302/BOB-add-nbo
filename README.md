# add nbo

Read 32-bit numbers stored in a file with a size of 4 bytes (network byte order) from two files and prints their sum.

## How to use

```
syntax : add-nbo <file1> <file2>
sample : add-nbo a.bin b.bin

# example
$ echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
$ echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin
$ ./add-nbo thousand.bin five-hundred.bin
1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)
```
