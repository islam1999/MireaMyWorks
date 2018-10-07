package ru.mirea.khitrov.labs.lab03.task01;

public class Main {
    public static void main(String[] args) {
        Dash dash;

        dash = new Dish();
        dash.PrintInformation();

        dash = new Dish(16, 3);
        dash.PrintInformation();

        dash = new Pan();
        dash.PrintInformation();

        dash = new Pan(18, 8);
        dash.PrintInformation();
    }
}
