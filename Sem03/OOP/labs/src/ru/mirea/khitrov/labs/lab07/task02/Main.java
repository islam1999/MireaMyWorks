package ru.mirea.khitrov.labs.lab07.task02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        LinkedList<String> list = new LinkedList<>();
        String s;
        System.out.println("Enter empty line to stop adding items:");
        while (!(s = reader.readLine()).isEmpty()) {
            list.add(s);
        }

        System.out.println(list);
        System.out.println("First: " + list.getFirst());
        System.out.println("Last: " + list.getLast());
        list.clear();
        System.out.println("List after clearing: " + list.toString());
    }
}
