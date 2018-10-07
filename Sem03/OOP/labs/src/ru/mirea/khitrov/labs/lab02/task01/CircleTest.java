package ru.mirea.khitrov.labs.lab02.task01;

public class CircleTest {
    public static void main(String[] args) {
        System.out.println(new Circle());
        System.out.println(new Circle(1, 2, 3));

        Circle c = new Circle(3, 4, 5);
        System.out.printf("Circle: x=%f y=%f r=%f\n", c.getX(), c.getY(), c.getR());

        c.setX(30.15);
        c.setR(11);
        System.out.println(c);
    }
}
