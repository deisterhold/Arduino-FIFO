/*
 * FIFO Buffer Test Program
 * Pushes then pops items onto FIFO buffer.
 * 
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 Daniel Eisterhold
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "FIFO.h"

FIFO myBuffer;

char test[64] = "Hello, World!!!\nHello, World!!!\nHello, World!!!\nHello, World!!!";

void setup() {
  //Open serial port at 9600 baud
  Serial.begin(9600);

  //Wait until the serial port has opened
  while (!Serial) delay(1);

  //Wait a little bit to make sure we don't get any garbage on the serial monitor
  delay(100);
}

void loop() {
  //Push the test array above onto the FIFO buffer
  for (byte i = 0; i < sizeof(test); i++) {
    Serial.write(test[i]);
    myBuffer.push(test[i]);
    delay(100);
  }

  Serial.write("\n\n");

  //Pop items off the FIFO buffer until it's empty
  while (myBuffer.size() > 0) {
    Serial.write((char)myBuffer.pop());
    delay(100);
  }

  while (1);
}
