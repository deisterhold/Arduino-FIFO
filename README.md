# Arduino-FIFO
Simple FIFO buffer for Arduino or other embedded processors

The default size of the buffer is 64 bytes.
With the default buffer size this library uses only 70 bytes of memory.
(64 byte buffer + 3 * 2 byte integers)

If you wish to change the buffer size then edit the ```#define FIFO_SIZE 64``` inside of "FIFO.h"
