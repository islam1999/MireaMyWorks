package ru.mirea.khitrov.labs.lab03.task01;

public class Dish extends Dash {
    protected double volume;

    public Dish() {
        super();
        volume = 0;
    }

    public Dish(double cost, double volume) {
        super(cost);
        this.volume = volume;
    }

    public double getVolume() {
        return volume;
    }

    public void setVolume(double volume) {
        this.volume = volume;
    }

    @Override
    public void PrintInformation() {
        System.out.println("Dish: volume=" + volume + ", cost=" + cost);
    }
}
