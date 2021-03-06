/*
 * 17. «Матричная алгебра»
 * Матрица должна быть представлена в памяти в виде указателя на массив указателей на строки матрицы
 * (одномерные динамические массивы).
 *
 * Операции:
 *   + создание матрицы из чисел текстового файла (первые два числа файла – размеры матрицы);
 *   + построчный вывод матрицы;
 *   + разность двух матриц;
 *   + сумма двух матриц;
 *   +умножение матрицы на число;
 *   +умножение матрицы на вектор;
 *   +умножение двух матриц;
 *   + присваивание одной матрицы другой;
 *   + проверка равенства двух матриц;
 *   + запись матрицы в текстовый файл (первые два числа файла – размеры матрицы).
 * + В демонстрационной программе предусмотреть запись матриц в текстовые файлы перед завершением программы.
 * + Реализовать матрицу таким образом, чтобы можно было легко изменить тип ее элементов (использовать шаблоны функций).
 */



#include <QApplication>
#include "MatrixGuiList.h"
#ifdef QT_DEBUG
#include <AutoTest.h>
#endif


int main(int argc, char *argv[]) {

    QApplication qApplication(argc, argv);

#ifdef QT_DEBUG
    AutoTest::runAllTests(argc, argv);
#endif

    MatrixGuiList mt;
    //mt.setMaximumSize(200, 250);
    mt.show();

    QApplication::exec();

    return 0;
}