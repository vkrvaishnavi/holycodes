#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#define TREECOLOR     "\x1B[32m"
#define BRANCHCOLOR   "\x1B[555555;35m"

#define RESET         "\x1B[0m"
#define RED           "\x1B[31m"
#define GRN           "\x1B[32m"
#define YEL           "\x1B[33m"
#define BLU           "\x1B[34m"
#define MAG           "\x1B[35m"
#define CYN           "\x1B[36m"
#define WHT           "\x1B[37m"
#define RESET         "\x1B[0m"

#define SPACE_OFFSET     10
#define CLEARSCRN     "\x1b[H\x1b[J"

#define MAX_TREE_WIDTH  9
#define MIN_TREE_WIDTH  3

#define STAR_CLR               "\x1B[33m"
#define STAR_DIAG_1   STAR_CLR "   ..\n"
#define STAR_DIAG_2   STAR_CLR " __/\\__\n"
#define STAR_DIAG_3   STAR_CLR " \\    /\n"
#define STAR_DIAG_4   STAR_CLR " /_  _\\\n"
#define STAR_DIAG_5   STAR_CLR "   \\/  \n"
#define STAR_DIAG_6   STAR_CLR "   ||\n"

int main () {
  int space_count;
  int star_count;
  int no_of_rows;
  int row;
  int tree_width;
  int min_tree_width;
  int i,j=1;
  const char* decor_clr[] = {
    RED, YEL, BLU, CYN, WHT
  };

  /* Get the height of the tree */
  printf("Enter the tree height: ");
  scanf("%d", &no_of_rows);


  while ( j < 10000 ){
    /* Clear the screen */
    printf(CLEARSCRN);

    /* Set the random seed for the decoration */
    srand( ((time(NULL) + 1) * 7) / 3);

    /* Print the star */
    printf("%0*c" STAR_DIAG_1 
           "%0*c" STAR_DIAG_2
           "%0*c" STAR_DIAG_3
           "%0*c" STAR_DIAG_4
           "%0*c" STAR_DIAG_5
           "%0*c" STAR_DIAG_6
           ,no_of_rows +SPACE_OFFSET-4, ' '
           ,no_of_rows +SPACE_OFFSET-4, ' '
           ,no_of_rows +SPACE_OFFSET-4, ' '
           ,no_of_rows +SPACE_OFFSET-4, ' '
           ,no_of_rows +SPACE_OFFSET-4, ' '
           ,no_of_rows +SPACE_OFFSET-4, ' '
           );
    /* Set the color of the leaves */
    printf(TREECOLOR);

    /* Print the Tree */
    for ( row = 1; row <= no_of_rows; row++) {
      min_tree_width = (row / MAX_TREE_WIDTH) * 3 + MIN_TREE_WIDTH;

      tree_width = row % MAX_TREE_WIDTH;

      if (row / MAX_TREE_WIDTH > 0) tree_width += min_tree_width;

      space_count = no_of_rows - tree_width + SPACE_OFFSET;
      if (space_count) printf("%0*c",space_count, ' ');
      star_count = 2 * tree_width;
      for ( i = 0; i < star_count; i++) {
        if(rand()%23 == 0) {
          printf("%s0" TREECOLOR, decor_clr[i % (sizeof(decor_clr)/sizeof(decor_clr[0])) ]);
        } else if(rand()%19 == 0) {
          printf("%s&" TREECOLOR, decor_clr[i % (sizeof(decor_clr)/sizeof(decor_clr[0])) ]);
        } else if(rand()%17 == 0) {
          printf("%s@" TREECOLOR, decor_clr[i % (sizeof(decor_clr)/sizeof(decor_clr[0])) ]);
        } else if(rand()%13 == 0) {
          printf("%s+" TREECOLOR, decor_clr[i % (sizeof(decor_clr)/sizeof(decor_clr[0])) ]);
        } else if(rand()%29 == 0) {
          printf("%s$" TREECOLOR, decor_clr[i % (sizeof(decor_clr)/sizeof(decor_clr[0])) ]);
        } else {
          printf("*");
        }
      }
      printf("\n");
    }
    printf(BRANCHCOLOR);
    for(i = 0; i< 4; i++)
      printf("%0*c|||\n", no_of_rows +SPACE_OFFSET-2, ' ');
    printf(RESET);
    sleep(1);
    j++;
  }
  return 0;
}
