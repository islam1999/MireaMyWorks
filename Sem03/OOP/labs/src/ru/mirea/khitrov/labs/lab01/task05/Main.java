package ru.mirea.khitrov.labs.lab01.task05;

public class Main {

    private static int calculateFactorial(int number) {
        if (number <= 0) {
            return 1;
        } else {
            int result = 1;
            for (int i = 1; i < number; i++) {
                result *= i;
            }
            return result;
        }
    }

    public static void main(String[] args) {
        System.out.println("factorial: " + calculateFactorial(5));
        System.out.println("factorial: " + calculateFactorial(10));
    }
}
