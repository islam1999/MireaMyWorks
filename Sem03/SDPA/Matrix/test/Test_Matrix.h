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

        for (int iteration = 0; iteration < iterations; ++iteration) {
            Matrix<double> matrix[3];
            int rows = qrand() % 100 + 2;
            int columns = qrand() % 100 + 2;

            QVector<QVector<double>> init_vec[3];
            for (int i = 0; i < 2; ++i) {
                init_vec[i].resize(rows);
                for (auto &column : init_vec[i]) {
                    column.resize(columns);
                    for (auto &elem : column) {
                        elem = qrand() / 3.1;
                    }
                }
            }

            init_vec[2].resize(rows);
            for (int i = 0; i < rows; ++i) {
                init_vec[2][i].resize(columns);
                for (int j = 0; j < columns; ++j) {
                    init_vec[2][i][j] = init_vec[0][i][j] + init_vec[1][i][j];
                }
            }
            for (int k = 0; k < 3; ++k) {
                matrix[k] = Matrix<double>(init_vec[k]);
            }

            QString desc = QString("add ") + QString::number(iteration);
            QTest::newRow(desc.toStdString().c_str()) << matrix[0] << matrix[1] << matrix[2];
        }
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

        for (int iteration = 0; iteration < iterations; ++iteration) {
            Matrix<double> matrix[3];
            int rows = qrand() % 100 + 2;
            int columns = qrand() % 100 + 2;

            QVector<QVector<double>> init_vec[3];
            for (int i = 0; i < 2; ++i) {
                init_vec[i].resize(rows);
                for (auto &column : init_vec[i]) {
                    column.resize(columns);
                    for (auto &elem : column) {
                        elem = qrand() / 3.1;
                    }
                }
            }

            init_vec[2].resize(rows);
            for (int i = 0; i < rows; ++i) {
                init_vec[2][i].resize(columns);
                for (int j = 0; j < columns; ++j) {
                    init_vec[2][i][j] = init_vec[0][i][j] - init_vec[1][i][j];
                }
            }
            for (int k = 0; k < 3; ++k) {
                matrix[k] = Matrix<double>(init_vec[k]);
            }

            QString desc = QString("subtract ") + QString::number(iteration);
            QTest::newRow(desc.toStdString().c_str()) << matrix[0] << matrix[1] << matrix[2];
        }
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

        for (int iteration = 0; iteration < iterations; ++iteration) {
            Matrix<double> matrix[2];
            int rows = qrand() % 100 + 1;
            int columns = qrand() % 100 + 1;

            QVector<QVector<double>> init_vec(rows);
            for (auto &column : init_vec) {
                column.resize(columns);
                for (auto &elem : column) {
                    elem = qrand() / 3.1;
                }
            }

            Matrix<double> mt(init_vec);
            matrix[0] = mt;
            matrix[1] = mt;

            QString desc = QString("equal ") + QString::number(iteration);
            QTest::newRow(desc.toStdString().c_str()) << matrix[0] << matrix[1];
        }
    }

    void test_equal() {
        QFETCH(Matrix<double>, first_matrix);
        QFETCH(Matrix<double>, second_matrix);

        QVERIFY(first_matrix == second_matrix);
    }

public:
    int iterations = 10;
};

DECLARE_TEST(Test_Matrix)

#endif //MATRIX_H
