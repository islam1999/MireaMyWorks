package ru.mirea.khitrov.labs.lab04.task01;

public class Main {
    public static void main(String[] args) {

        Nameable nameable = new Planet("Earth");
        System.out.println(nameable.getName());

        nameable = new Car("Subaru");
        System.out.println(nameable.getName());

        nameable = new Animal("Barsic");
        System.out.println(nameable.getName());
    }
}
