#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define RESULT_LENGTH 11 

void process_line(const char* input, char* result, size_t result_size) 
{
    int digits_present[10] = { 0 };
    int i;

    for (i = 0; input[i] != '\0'; i++) 
    {
        if (isdigit(input[i])) 
        {
            int digit = input[i] - '0'; 
            digits_present[digit] = 1;
        }
    }

    int all_digits_present = 1;
    for (i = 0; i < 10; i++) 
    {
        if (!digits_present[i]) 
        {
            all_digits_present = 0;
            break;
        }
    }

    if (all_digits_present) 
    {
        strcpy_s(result, result_size, "-1");
        return;
    }

    int index = 0;
    for (i = 9; i >= 0; i--) 
    {
        if (!digits_present[i]) 
        {
            if (index < result_size - 1) 
            {
                result[index++] = i + '0'; 
            }
        }
    }
    result[index] = '\0'; 

    if (index == 0) 
    {
        result[0] = '\0';
    }
}

int main() 
{
    FILE* input_file, * output_file;
    char line[MAX_LENGTH];
    char result[RESULT_LENGTH]; 

    errno_t input_error, output_error;

    input_error = fopen_s(&input_file, "labainf3.txt", "r");
    output_error = fopen_s(&output_file, "labaresult.txt", "w");

    if (input_error != 0) 
    {
        printf("Ошибка labainf3.", input_error);
        return 1;
    }

    if (output_error != 0) 
    {
        printf("Ошибка labaresult.txt.", output_error);
        if (input_file != NULL) 
        {
            fclose(input_file);
        }
        return 1;
    }


    while (fgets(line, sizeof(line), input_file) != NULL) 
    {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') 
        {
            line[len - 1] = '\0';
        }

        process_line(line, result, sizeof(result));

        fprintf(output_file, "%s\n", result);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Обработка завершена\n");

    return 0;
}