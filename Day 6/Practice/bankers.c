#include <stdio.h>
#include<stdbool.h>

int main() {
    int p, r, curr_seq = 0;

    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of resource types: ");
    scanf("%d", &r);
    
    int alloc[p][r], max[p][r], need[p][r], avail[p][r], safe_seq[p], work[r];
    bool finish[p], finished = false;
    bool proc_safe = true;
    
   	printf("\nEntering Allocation matrix of size %dx%d...\n",p,r);
    for (int i = 0; i < p; i++) {
        printf("Enter %d instances of P%d: ",r, i);
        for (int j = 0; j < r; j++) {
        	scanf("%d", &alloc[i][j]);
   		}
    }

	printf("\nEntering Max needs matrix of size %dx%d...\n",p,r);
    for (int i = 0; i < p; i++) {
        printf("Enter %d instances of P%d: ",r, i);
        for (int j = 0; j < r; j++) {
        	scanf("%d", &max[i][j]);
   		}
   	}	
	
   	printf("Enter initial %d available instances: ",r);
   	for (int j = 0; j < r; j++) {
        scanf("%d", &work[j]);
    }
	
	//
	for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
        	need[i][j] = max[i][j] - alloc[i][j];
    	}
    }
	
	for (int proc = 0; proc < p; proc++) {
	
		for (int i = 0; i < p; i++) {
			if (finish[i] == false) {
				proc_safe = true;
				for (int j = 0; j < r; j++) {
					if (need[i][j] > work[j]) {
						proc_safe = false;
						break;
						}
				}
				if (proc_safe == true) {
					finish[i] = true;
					safe_seq[curr_seq] = i;
					curr_seq++;
					for (int j = 0; j < r; j++)
						work[j] = work[j] + max[i][j];
					break;
				}
			}
		}
	}
	
    printf("\nProcess\tAllocation\tMax Needs\tAvailable\tCurrent Needs\n");
	
	for (int i = 0; i < p; i++) {
		if (finish[i] != true)
			printf("Unsafe Process!");
	}		
	printf("\nSafe Sequence:");
	for (int i = 0; i < p-1; i++) {
		printf("P%d->",safe_seq[i]);
	}
	printf("P%d",safe_seq[p]);


    return 0;
}

