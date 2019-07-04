#include "main.h"
#include <stdlib.h>
#include "mstn_uart.h"
#include <stdio.h>
#include "mstn_clk.h"
#include <cstring>
#include <mstn.h>

int main(int argc, char *argv[])
{
    
    Delay(4000);
    char msg_transmit[128]; //Сообщение для отправки
    char msg_receive[128];  //Принятое сообщение
    int res;                //Для хранения одного байта из буфера и последующего преобразования его в символ 
    int k;                  //Порядковый номер элемента массива
    int count;              //Число символов в буфере
    
    while(1)
    {
        UART_Begin(SERIAL1, 300);                 //Инициализация последоватлеьного соединения
        //Отправка
        
        printf("Enter message:\n");
        scanf("%s", msg_transmit);                //Ввод сообщения
        printf("Your msg: %s\n", msg_transmit);   //Вывод этого сообщения на экран
        
        printf("Ready... \n");
        Delay(1000);
        
        UART_PrintStr(SERIAL1, msg_transmit);     //Передача строки через интерфейс UART
        UART_Flush(SERIAL1);                      //Ожидание передачи исходящего сообщения. Почему-то не работает ;(
        
        
        
        //Приём
        
        UART_Wait(SERIAL1, 1000);                 //Ожидание окончания приема посылки 
     
        count = UART_Available(SERIAL1);          //Число символов в буфере
        printf("Number of characters in buffer: %d\n", count);
        
        k = 0;
        while(UART_Available(SERIAL1) != 0) //Пока буфер не будет пуст
        {
            res = UART_Read(SERIAL1);
            msg_receive[k] = (char)res; //Преобразование типа данных
            k++;
        }
        
        printf("Received message: %s\n", msg_receive);

        memset(msg_receive, 0, sizeof(msg_receive)); //Очищение массива
        UART_End(SERIAL1);
    }
    return EXIT_SUCCESS;
}