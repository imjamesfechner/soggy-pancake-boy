#include <stdio.h>
#include <stdlib.h>

void print_array(int *stack, int h) {
    for (int i=0; i<h; i++) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

void flip(int stack[], int n) {
	int temp = 0;
	int m = n;
	for(int i=0; i<n; i++) {
		temp = stack[i];
		stack[i] = stack[n];
		stack[n] = temp;
		n--;
	}
	for(int i=0; i<m+1; i++) {
		stack[i] = stack[i]*-1;
	}
}

int is_max(int stack[], int n) {
	int max, i;
	for (max=0, i=0; i<n; i++) {
		if (abs(stack[max]) <= abs(stack[i])) {
			max = i;
		}
	}
	return max;
}

int pancake_sort(int *stack, int height) {
	int moves = 0;
	for (int h=height; h>1; h--) {
		int max = is_max(stack, h);
		if (max != h-1) {
			if(max != 0) {
				flip(stack, max);
				moves++;
				print_array(stack, height);
			}
			
			if(stack[0] > 0) {
				stack[0] = stack[0]*-1;
				moves++;
				print_array(stack, height);
			}	
			
			flip(stack, h-1);
			moves++;
			print_array(stack, height);
		}
	}
	for(int i=height-1;i>0;i--) {
		if(stack[i] < 0) {
			flip(stack, i);
			moves++;
			print_array(stack, height);
			
			stack[0] = stack[0]*-1;
			moves++;
			print_array(stack, height);
			
			flip(stack, i);
			moves++;
			print_array(stack, height);
		}
	}
	if(stack[0] < 0) {
		stack[0] = stack[0]*-1;
		moves++;
		print_array(stack, height);
	}
	return moves;
}

int main(void){
	int h;
	int j;
	printf("How many pancakes in your stack? ");
	scanf("%d", &h);
	int *stack = malloc(sizeof(int) * h);
	
	for(int i=0; i<h; i++) {
		if (i<1) {
			printf("How big is the first pancake? ");
			scanf("%d", &j);
			stack[i] = j;
		} else {
			printf("How big is the next pancake? ");
			scanf("%d", &j);
			stack[i] = j;
		}
	}	
	
	print_array(stack, h);
	int moves = pancake_sort(stack, h);
	printf("Moves: %d\n", moves);
	return 0;
}