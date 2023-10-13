#include <stdio.h>

int main(void) {

  //initializing the pointer named mydoc  
  FILE *mydoc;

  //opening a file in write mode
  mydoc = fopen("text.txt", "w");
  
  if (mydoc != NULL) {
    int i = 0, no;
    for (i = 0; i < 5; i++) {
      printf("Enter %d Number : ", i + 1);
      scanf("%d", &no);
      fprintf(mydoc, "%d\n", no);
    }
    fclose(mydoc); // Close the file after writing.
  } else {
    printf("Error opening the file!\n");
  }
  
   //opening the file in read mode

  mydoc = fopen("text.txt", "r");
  if (mydoc != NULL) {
    int no;
    while (fscanf(mydoc, "%d", &no) != EOF) {

      //printing numbers till end of the file 
      printf("%d\n", no);
    }
    fclose(mydoc); // Close the file after reading.
  } else {

    printf("Error opening the file!\n");//printing error message 
  }
  return 0; // Add a return statement to indicate successful execution.
}
