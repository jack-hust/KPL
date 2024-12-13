#include <stdio.h>
#include "reader.h"

FILE *inputStream;
int lineNo, colNo;
int currentChar;

int readChar(void) {
  currentChar = getc(inputStream);
  colNo++;
  if (currentChar == '\n') {
    lineNo++;
    colNo = 0;
  }
  return currentChar;
}

int openInputStream(char *fileName) {
  inputStream = fopen(fileName, "rt");
  if (inputStream == NULL)
    return IO_ERROR;
  lineNo = 1;
  colNo = 0;
  readChar();
  return IO_SUCCESS;
}

void closeInputStream() {
  fclose(inputStream);
}

// Hàm mới: In toàn bộ nội dung file đã đọc
void printFileContent(void) {
  rewind(inputStream); // Quay về đầu file
  lineNo = 1;
  colNo = 0;

  while (readChar() != EOF) {
    putchar(currentChar); // In ký tự ra màn hình
  }
}
