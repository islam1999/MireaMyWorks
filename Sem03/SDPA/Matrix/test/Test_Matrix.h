#ifndef MATRIX_H
#define MATRIX_H

#include "AutoTest.h"
#include "Matrix.h"


Q_DECLARE_METATYPE(Matrix<double>);

class Test_Matrix : public QObject {

Q_OBJECT

private slots:

    void test_addition_data() {

        QTest::addColumn<Matrix<double>>("first_matrix");
        QTest::addColumn<Matrix<double>>("second_matrix");
        QTest::addColumn<Matrix<double>>("result_matrix");

        Matrix<double> left;
        Matrix<double> right;
        Matrix<double> result;
        QTest::newRow("add 1") << left << right << result;
    }

    void test_addition() {
        QFETCH(Matrix<double>, first_matrix);
        QFETCH(Matrix<double>, second_matrix);
        QFETCH(Matrix<double>, result_matrix);

        QCOMPARE(first_matrix + second_matrix, result_matrix);
    }

    void test_subtraction_data() {
        QTest::addColumn<Matrix<double>>("first_matrix");
        QTest::addColumn<Matrix<double>>("second_matrix");
        QTest::addColumn<Matrix<double>>("result_matrix");

        Matrix<double> left;
        Matrix<double> right;
        Matrix<double> result;
        QTest::newRow("sub 1") << left << right << result;
    }

    void test_subtraction() {
        QFETCH(Matrix<double>, first_matrix);
        QFETCH(Matrix<double>, second_matrix);
        QFETCH(Matrix<double>, result_matrix);

        QCOMPARE(first_matrix - second_matrix, result_matrix);
    }

    void test_equal_data() {
        QTest::addColumn<Matrix<double>>("first_matrix");
        QTest::addColumn<Matrix<double>>("second_matrix");

        Matrix<double> left;
        Matrix<double> right;

        QTest::newRow("equal 1") << left << right;
    }

    void test_equal() {
        QFETCH(Matrix<double>, first_matrix);
        QFETCH(Matrix<double>, second_matrix);

        QVERIFY(first_matrix == second_matrix);
    }
};

DECLARE_TEST(Test_Matrix)

#endif //MATRIX_H

