/*
Проект "Однорукий бандит"
Правила є досить вільними, наприклад, в ньому є послідовність випадково згенерованих цифр заданої довжини.
Якщо принаймні одна цифра - сімка, гравцеві повертається його ставка.
Якщо всі цифри однакові, гравець виграє і його ставка подвоюється, але якщо всі цифри - сімки, то ставка потроюється.
Якщо принаймні одна третина цифр однакові, гравець виграє його ставку.
 */

#include <stdio.h>
#include <stdlib.h>
#define ONCE_AND_MORE_SEVEN 1
#define THIRD_PART_SAME 2
#define ALL_NUMS_SAME 3
#define ALL_NUMS_SEVEN 4

int initNumRow(int array[], int NumLength){
    printf("[ГРА] - Ставка прийнята. Гра почалась! Такий твій ряд:\n");
    for (int i = 0; i < NumLength; ++i) {
        array[i] = rand()%10;
        printf("[ГРА] - %d-а цифра: %d\n", i+1, array[i]);
    }
}

int winning(int bet, int array[], int NumLength){
    int flag = 0;
    int tmp;
    int entries[10] = {0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < NumLength; ++j) {
            if (array[j] == i) entries[i]++;
        }
        if (entries[i] >= NumLength/3){ flag = THIRD_PART_SAME; tmp = i;
            if (entries[i] == NumLength){ flag = ALL_NUMS_SAME; tmp = i;
                if (i == 7){ flag = ALL_NUMS_SEVEN; tmp = i;}}}
        else if (i == 7 && entries[i] > 0){ flag = ONCE_AND_MORE_SEVEN; tmp = i;}

    }

    switch (flag) {

        case THIRD_PART_SAME:
            printf("[ГРА] - Ставку розміром %d повернено: цифра %d випала %d разів!", bet, tmp, entries[tmp]);
            break;
        case ONCE_AND_MORE_SEVEN:
            printf("[ГРА] - Виграш становить %d: сімка випала %d разів!", bet*2, entries[tmp]);
            break;
        case ALL_NUMS_SAME:
            printf("[ГРА] - Виграш становить %d: всі цифри однакові [%d]!", bet*3, tmp);
            break;
        case ALL_NUMS_SEVEN:
            printf("[ГРА] - Виграш становить %d: всі цифри однакові [%d]!", bet*4, tmp);
            break;
        default:
            printf("[ГРА] - На жаль, в цей раз ви програли.");
            break;

    }

}

int main(){

    int NumLength, bet;
    printf("ОДНОРУКИЙ БАНДИТ\n");
    printf("[ГРА] - Скільки цифр буде в ряді?\n");
    printf("[ГРАВЕЦЬ] - Нехай буде: ");
    scanf("%d", &NumLength);
    printf("[ГРА] - Яка твоя ставка?\n");
    printf("[ГРАВЕЦЬ] - Ставка: ");
    scanf("%d", &bet);
    int NumRow[NumLength];
    initNumRow(NumRow, NumLength);
    winning(bet, NumRow, NumLength);
    return 0;
}