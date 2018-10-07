package ru.mirea.khitrov.labs.lab01.task01;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("elements count: ");

        int size = Math.abs(scanner.nextInt());
        int[] array = new int[size];

        for (int i = 0; i < array.length; i++) {
            array[i] = scanner.nextInt();
        }

        int sum = 0;
        for (int anArray : array) {
            sum += anArray;
        }
        System.out.println("for: " + sum);

        int i = sum = 0;
        while (i < array.length) {
            sum += array[i++];
        }
        System.out.println("while: " + sum);

        i = sum = 0;
        do {
            sum += array[i++];
        } while (i < array.length);
        System.out.println("do while: " + sum);
    }
}
