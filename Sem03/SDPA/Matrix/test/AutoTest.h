#ifndef MATRIX_AUTOTEST_H
#define MATRIX_AUTOTEST_H

#include <QTest>
#include <QList>
#include <QString>
#include <QSharedPointer>

namespace AutoTest {
    typedef QList<QObject *> TestList;

    inline TestList &testList() {
        static TestList list;
        return list;
    }

    inline bool hasObject(QObject *object) {
        auto &list = testList();
        if (list.contains(object)) {
            return true;
        }

        for (auto *test : list) {
            if (test->objectName() == object->objectName()) {
                return true;
            }
        }
        return false;
    }

    inline void addTest(QObject *object) {
        TestList &list = testList();
        if (!hasObject(object)) {
            list.append(object);
        }
    }

    inline int runAllTests(int argc, char *argv[]) {
        int ret = 0;

        for (auto *test : testList()) {
            ret += QTest::qExec(test, argc, argv);
        }

        return ret;
    }
}

template<class T>
class Test {
public:
    QSharedPointer<T> child;

    explicit Test(const QString &name) : child(new T) {
        child->setObjectName(name);
        AutoTest::addTest(child.data());
    }
};

#define DECLARE_TEST(className) static Test<className> test(#className);


#endif //MATRIX_AUTOTEST_H