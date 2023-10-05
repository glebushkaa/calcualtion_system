#include <stdio.h>

enum Result {
    DIVISION_BY_ZERO, SUCCESS, FUNCTION_UNDEFINED
};

struct CalculationResult {
    enum Result result;
    float y;
};

float get_float_from_input(char* placeholder);

struct CalculationResult calculate_system(float a, float b, float x);

void handle_calculation_result(struct CalculationResult calculation_result);

int main() {
    float a = get_float_from_input("a");
    float b = get_float_from_input("b");
    float x = get_float_from_input("x");

    struct CalculationResult calculation_result = calculate_system(a, b, x);

    handle_calculation_result(calculation_result);
}


float get_float_from_input(char* placeholder) {
    float value;
    printf("Input %s:", placeholder);
    scanf("%f", &value);
    printf("\n");
    return value;
}

struct CalculationResult calculate_system(float a, float b, float x) {
    struct CalculationResult result;
    if (1 <= x && x < 3) {
        if (a == 0) {
            result.result = DIVISION_BY_ZERO;
            return result;
        }
        float y = 9 / (a * x);
        result.result = SUCCESS;
        result.y = y;
        return result;
    }
    if (x != 3) {
        result.result = FUNCTION_UNDEFINED;
        return result;
    }
    float y = a * x * x + x + b;
    result.y = y;
    result.result = SUCCESS;
    return result;
}

void handle_calculation_result(struct CalculationResult calculation_result) {
    switch (calculation_result.result) {
        case SUCCESS: {
            printf("Result: %f", calculation_result.y);
            break;
        }
        case DIVISION_BY_ZERO: {
            printf("Division by zero");
            break;
        }
        case FUNCTION_UNDEFINED : {
            printf("Function undefined");
            break;
        }
    }
}

