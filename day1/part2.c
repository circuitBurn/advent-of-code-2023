#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE* ptr;
  char* line = NULL;
  size_t len = 0;
  size_t read;
  char c;

  int total = 0;

  ptr = fopen("input.txt", "r");

  if (NULL == ptr) {
    printf("file can't be opened \n");
  }

  if (ptr == NULL)
    exit(EXIT_FAILURE);

  while ((read = getline(&line, &len, ptr)) != -1) {
    for (int i = 0; i < read; i++) {
      c = line[i];

      if (c >= '0' && c <= '9') {
        total = total + ((c - '0') * 10);
        printf("%d", c - '0');
        break;
      } else if (c == 'o' && i + 2 < len) {
        // One
        if (line[i + 1] == 'n' && line[i + 2] == 'e') {
          total = total + 10;
          break;
        }
      } else if (c == 't') {
        // Two
        if (i + 2 < len) {
          if (line[i + 1] == 'w' && line[i + 2] == 'o') {
            total = total + 20;
            break;
          }
        }

        // Three
        if (i + 4 < len) {
          if (line[i + 1] == 'h' && line[i + 2] == 'r' && line[i + 3] == 'e' && line[i + 4] == 'e') {
            total = total + 30;
            break;
          }
        }
      } else if (c == 'f' && i + 3 < len) {
        // Four
        if (line[i + 1] == 'o' && line[i + 2] == 'u' && line[i + 3] == 'r') {
          total = total + 40;
          break;
        }

        // Five
        if (line[i + 1] == 'i' && line[i + 2] == 'v' && line[i + 3] == 'e') {
          total = total + 50;
          break;
        }
      } else if (c == 's') {
        // Six
        if (i + 2 < len) {
          if (line[i + 1] == 'i' && line[i + 2] == 'x') {
            total = total + 60;
            break;
          }
        }

        // Seven
        if (i + 4 < len) {
          if (line[i + 1] == 'e' && line[i + 2] == 'v' && line[i + 3] == 'e' && line[i + 4] == 'n') {
            total = total + 70;
            break;
          }
        }
      } else if (c == 'e' && i + 4 < len) {
        // Eight
        if (line[i + 1] == 'i' && line[i + 2] == 'g' && line[i + 3] == 'h' && line[i + 4] == 't') {
          total = total + 80;
          break;
        }
      } else if (c = 'n' && i + 3 < len) {
        // Nine
        if (line[i + 1] == 'i' && line[i + 2] == 'n' && line[i + 3] == 'e') {
          total = total + 90;
          break;
        }
      }
    }

    // Find the last number
    for (int j = read - 1; j >= 0; j--) {
      c = line[j];

      if (c >= '0' && c <= '9') {
        total = total + c - '0';
        printf("%d", c - '0');
        break;
      } else if (c == 'o' && j + 2 < len) {
        // One
        if (line[j + 1] == 'n' && line[j + 2] == 'e') {
          total = total + 1;
          break;
        }
      } else if (c == 't') {
        // Two
        if (j + 2 < len) {
          if (line[j + 1] == 'w' && line[j + 2] == 'o') {
            total = total + 2;
            break;
          }
        }

        // Three
        if (j + 4 < len) {
          if (line[j + 1] == 'h' && line[j + 2] == 'r' && line[j + 3] == 'e' && line[j + 4] == 'e') {
            total = total + 3;
            break;
          }
        }
      } else if (c == 'f' && j + 3 < len) {
        // Four
        if (line[j + 1] == 'o' && line[j + 2] == 'u' && line[j + 3] == 'r') {
          total = total + 4;
          break;
        }

        // Five
        if (line[j + 1] == 'i' && line[j + 2] == 'v' && line[j + 3] == 'e') {
          total = total + 5;
          break;
        }
      } else if (c == 's') {
        // Six
        if (j + 2 < len) {
          if (line[j + 1] == 'i' && line[j + 2] == 'x') {
            total = total + 6;
            break;
          }
        }

        // Seven
        if (j + 4 < len) {
          if (line[j + 1] == 'e' && line[j + 2] == 'v' && line[j + 3] == 'e' && line[j + 4] == 'n') {
            total = total + 7;
            break;
          }
        }
      } else if (c == 'e' && j + 4 < len) {
        // Eight
        if (line[j + 1] == 'i' && line[j + 2] == 'g' && line[j + 3] == 'h' && line[j + 4] == 't') {
          total = total + 8;
          break;
        }
      } else if (c = 'n' && j + 3 < len) {
        // Nine
        if (line[j + 1] == 'i' && line[j + 2] == 'n' && line[j + 3] == 'e') {
          total = total + 9;
          break;
        }
      }
    }
  }

  printf("Total: %d", total);

  fclose(ptr);
  return 0;
}
