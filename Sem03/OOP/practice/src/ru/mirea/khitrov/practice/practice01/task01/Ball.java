package ru.mirea.khitrov.practice.practice01.task01;

public class Ball {
    private int radius;

    public Ball(int radius) {
        this.radius = radius;
    }

    public int getRadius() {
        return radius;
    }

    public void setRadius(int radius) {
        this.radius = radius;
    }

    @Override
    public String toString() {
        return "Ball {radius=" + radius + '}';
    }
}
