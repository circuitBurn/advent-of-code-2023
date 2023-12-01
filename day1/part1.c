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

  while ((read = getline(&line, &len, ptr)) != -1)
  {
    for (int i = 0; i < read; i++)
    {
        c = line[i];
        if (c >= '0' && c <= '9')
        {
            total = total + ((c - '0') * 10);
            break;
        }
    }

    for (int j = read - 1; j >= 0; j--)
    {
        c = line[j];
        if (c >= '0' && c <= '9')
        {
            total = total + c - '0';
            break;
        }
    }
  }

  printf("Total: %d", total);

  fclose(ptr);
  return 0;
}