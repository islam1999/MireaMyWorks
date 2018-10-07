package ru.mirea.khitrov.labs.lab03.task01;

public class Pan extends Dash {
    protected double volume;

    Pan() {
        super();
        volume = 0;
    }

    Pan(double cost, double volume) {
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
        System.out.println("Pan: volume=" + volume + ", cost=" + cost);
    }
}
