#include<stdio.h>
// Function to move a disk from one pole to another
void towerOfHanoi(int disk, char source, char dest, char aux) {
 if (disk == 1) {
 printf("Move disk 1 from %c to %c\n", source, dest);
 return;
 }
 towerOfHanoi(disk - 1, source, aux, dest);
 printf("Move disk %d from %c to %c\n", disk, source, dest);
 towerOfHanoi(disk - 1, aux, dest, source);
}
int main() {
 int numDisks;
 printf("Enter the number of disks: ");
 scanf("%d", &numDisks);
 towerOfHanoi(numDisks, 'A', 'C', 'B');
 return 0;
}
