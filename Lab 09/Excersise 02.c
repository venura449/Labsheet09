#include <stdio.h>
#include <string.h>

struct purchase {
  char itemNo[15];
  char itemName[50];
  float unitprice;
  int Quantity;
};

int main(void) {
  struct purchase item[4];
  FILE *mydoc;
  mydoc = fopen("purchase.txt", "w");
  if (mydoc != NULL) {
    int i = 0;
    printf("%10s %10s %10s %10s\n", "ItemID", "ItemName", "Quantity", "Price");
    for (i = 0; i < 4; i++) {
      scanf("%s %s %d %f", item[i].itemNo, item[i].itemName, &item[i].Quantity,
            &item[i].unitprice);
      fprintf(mydoc, "%10s %10s %10d %10.2f\n", item[i].itemNo, item[i].itemName,
              item[i].Quantity, item[i].unitprice);
    }

  } else {
    printf("Error ! Can't Write in File");
  }
  fclose(mydoc);
  mydoc = fopen("purchase.txt", "r");
  if (mydoc != NULL) {
    int i = 0;
    float total = 0;
    printf("\n\n%10s %10s %10s %15s %10s\n\n", "ItemID", "ItemName","" "Quantity","Unit Price","totalPrice");
    while (fscanf(mydoc, "%s %s %d %f", item[i].itemNo, item[i].itemName,
                  &item[i].Quantity, &item[i].unitprice) != EOF) {
      
      printf("%10s %10s %10d %10.2f %10.2f\n", item[i].itemNo, item[i].itemName,
             item[i].Quantity,item[i].unitprice, item[i].unitprice * item[i].Quantity);
      total += item[i].Quantity * item[i].unitprice;
    }
    printf("\n%10s\t\t\t\t\t\t\t\t\t%.2f", "Total", total);
  } else {
    printf("Error ! opening File ! ");
  }
}