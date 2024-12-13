#include <stdio.h>
#include <stdlib.h>
#include "reader.h"
#include "parser.h"

/******************************************************************/

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printf("parser: no input file.\n");
    return -1;
  }

  if (openInputStream(argv[1]) == IO_ERROR) {
    printf("Can't read input file!\n");
    return -1;
  }

  // In nội dung file đã đọc
  printFileContent();
  printf("\n");
  printf("******************************************************************");
  printf("\n");

  // Gọi hàm xử lý tệp (compile)
  if (compile(argv[1]) == IO_ERROR) {
    printf("Can't parse the file!\n");
    closeInputStream();
    return -1;
  }

  closeInputStream();
  return 0;
}
