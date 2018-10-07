package ru.mirea.khitrov.labs.lab04.task01;

public class Planet implements Nameable {
    private String planetName;

    public Planet(String planetName) {
        this.planetName = planetName;
    }

    public String getPlanetName() {
        return planetName;
    }

    public void setPlanetName(String planetName) {
        this.planetName = planetName;
    }

    @Override
    public String getName() {
        return planetName;
    }
}
