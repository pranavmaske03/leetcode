#include<stdio.h>

typedef struct {
    char name[3]; // Element name (max 2 chars + null terminator)
    int count;
} Atom;

int cmp(const void *a, const void *b) {
    return strcmp(((Atom *)a)->name, ((Atom *)b)->name);
}

char* countOfAtoms(char* formula) {
    int len = strlen(formula);
    Atom atoms[1000];
    int count = 0;
    int stack[1000];
    int top = -1;
    int i = 0;

    while (i < len) {
        if (isupper(formula[i])) {
            // Read the element
            int j = 0;
            atoms[count].name[j++] = formula[i++];
            while (i < len && islower(formula[i])) {
                atoms[count].name[j++] = formula[i++];
            }
            atoms[count].name[j] = '\0';

            // Read the count
            int num = 0;
            while (i < len && isdigit(formula[i])) {
                num = num * 10 + (formula[i++] - '0');
            }
            if (num == 0) num = 1;
            atoms[count].count += num;
            count++;
        } else if (formula[i] == '(') {
            // Push the current count to stack
            stack[++top] = count;
            i++;
        } else if (formula[i] == ')') {
            // Pop count from stack
            int prev_count = stack[top--];
            int multiplier = 0;
            i++;
            while (i < len && isdigit(formula[i])) {
                multiplier = multiplier * 10 + (formula[i++] - '0');
            }
            if (multiplier == 0) multiplier = 1;

            for (int j = prev_count; j < count; j++) {
                atoms[j].count *= multiplier;
            }
        }
    }

    // Aggregate counts to handle multiple same atoms
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(atoms[i].name, atoms[j].name) == 0) {
                atoms[i].count += atoms[j].count;
                for (int k = j; k < count - 1; k++) {
                    atoms[k] = atoms[k + 1]; // Shift left
                }
                count--; // Decrease the count of distinct atoms
                j--; // Adjust index after shift
            }
        }
    }

    // Sorting atoms
    qsort(atoms, count, sizeof(Atom), cmp);

    // Prepare output
    char *result = (char *)malloc(1000 * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < count; i++) {
        strcat(result, atoms[i].name);
        if (atoms[i].count > 1) {
            char count_str[10];
            sprintf(count_str, "%d", atoms[i].count);
            strcat(result, count_str);
        }
    }

    return result;
}

int main()
{


    return 0;
}