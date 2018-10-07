package ru.mirea.khitrov.labs.lab01.task04;

import java.util.Arrays;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Random random = new Random();
        int length = random.nextInt(20) + 1;
        int[] a = new int[length];

        System.out.print("Default array: ");
        for (int i = 0; i < a.length; i++) {
            a[i] = random.nextInt() % 1000;
            System.out.print(a[i] + " ");
        }
        System.out.println();

        Arrays.sort(a);

        System.out.print("Sorted array: ");
        for (int i: a) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
