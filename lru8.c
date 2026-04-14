#include <stdio.h>

int main() {
    int frames = 3;
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int n = 12;

    int frame[3], time[3];
    int i, j, pos, min;
    int faults = 0, hits = 0, counter = 0;

    // Initialize frames
    for(i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("Page Replacement Process:\n");

    for(i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check for hit
        for(j = 0; j < frames; j++) {
            if(frame[j] == page) {
                counter++;
                time[j] = counter;
                hits++;
                found = 1;
                break;
            }
        }

        // If page not found → fault
        if(found == 0) {
            min = 0;
            for(j = 1; j < frames; j++) {
                if(time[j] < time[min]) {
                    min = j;
                }
            }

            counter++;
            frame[min] = page;
            time[min] = counter;
            faults++;
        }

    return 0;
}        // Print frame status
        printf("\nPage %d -> ", page);
        for(j = 0; j < frames; j++) {
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
    }

    // Results
    printf("\n\nTotal Page Hits = %d", hits);
    printf("\nTotal Page Faults = %d", faults);

    float hit_ratio = (float)hits / n * 100;
    float fault_ratio = (float)faults / n * 100;

