package ru.mirea.khitrov.labs.lab03.task01;

public abstract class Dash {
    protected double cost;

    public Dash() {
        cost = 0;
    }

    public Dash(double cost) {
        this.cost = cost;
    }

    public double getCost() {
        return cost;
    }

    public void setCost(double cost) {
        this.cost = cost;
    }

    public abstract void PrintInformation();
}
