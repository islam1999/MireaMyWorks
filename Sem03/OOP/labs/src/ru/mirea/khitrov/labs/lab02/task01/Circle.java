package ru.mirea.khitrov.labs.lab02.task01;

public class Circle {
    private double x, y, r;

    public Circle() {
        this(0, 0, 0);
    }

    public Circle(double x, double y, double r) {
        this.x = x;
        this.y = y;
        this.r = r;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getR() {
        return r;
    }

    public void setR(double r) {
        this.r = r;
    }

    @Override
    public String toString() {
        return "Circle {" +
                "x=" + x +
                ", y=" + y +
                ", r=" + r +
                '}';
    }
}
