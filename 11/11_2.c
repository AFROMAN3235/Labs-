#include <stdio.h>
#include <stdlib.h>

// Рекурсивная функция для вычисления суммы положительных чисел массива
int sumPositive(int *arr, int size, int index, int sum) {
// Базовый случай: если индекс выходит за границы массива, возвращаем сумму
if (index >= size) {
return sum;
}

// Рекурсивный случай: если текущий элемент положительный, добавляем его к сумме
if (arr[index] > 0) {
    sum += arr[index];
}

// Рекурсивный вызов для следующего элемента массива
return sumPositive(arr, size, index + 1, sum);
}

int main() {
int size;

// Ввод размера массива
printf("Введите размер массива: ");
scanf("%d", &size);

// Выделение памяти под массив
int *arr = (int*)malloc(size * sizeof(int));

// Заполнение массива случайными числами в диапазоне от -10 до 10
for (int i = 0; i < size; i++) {
    arr[i] = rand() % 21 - 10;
}

// Вывод массива на экран
printf("Массив: ");
for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
}
printf("\n");

// Вызов рекурсивной функции для вычисления суммы положительных чисел массива
int sum = sumPositive(arr, size, 0, 0);

// Вывод результата на экран
printf("Сумма положительных чисел массива: %d\n", sum);

// Освобождение памяти, выделенной под массив
free(arr);

return 0;
}





