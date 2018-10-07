package ru.mirea.khitrov.practice.practice05.task02;

public class Main {
    public static void main(String[] args) {
        printToN(10);
    }

    public static void printToN(int n) {
        printToN(n, n);
    }

    public static void printToN(int startN, int currentN) {
        System.out.println(startN - currentN + 1);
        if (currentN - 1 == 0) {
            return;
        }
        printToN(startN, currentN-1);
    }
}
