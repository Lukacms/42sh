/*
** EPITECH PROJECT, 2021
** my_sort_int_array.c
** File description:
** task07d04
*/

static void my_sort_in_arraybis(int *array, int size, int i)
{
    int replace;

    for (int a = 0; a != size; a++) {
        if (array[i] < array [a]) {
            replace = array[a];
            array[a] = array[i];
            array[i] = replace;
        }
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        my_sort_in_arraybis(array, size, i);
    }
}
