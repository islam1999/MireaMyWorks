package ru.mirea.khitrov.labs.lab04.task01;

public class Car implements Nameable {
    private String carType;

    public Car(String carType) {
        this.carType= carType;
    }

    public String getCarType() {
        return carType;
    }

    public void setCarType(String carType) {
        this.carType = carType;
    }

    @Override
    public String getName() {
        return carType;
    }
}
