package ru.mirea.khitrov.practice.practice06.task03;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Random;

public class Student {
    private int score;

    public static void main(String[] args) {
        ArrayList<Student> students = new ArrayList<>();
        System.out.println("Generated:");
        for (int i = 0; i < 50; i++) {
            students.add(new Student(new Random().nextInt(100)));
            System.out.println(students.get(i));
        }

        System.out.println("===============================\nSorted:");
        students.sort(Comparator.comparingInt(s -> s.score));
        for (Student s : students) {
            System.out.println(s);
        }
    }

    public Student(int score) {
        this.score = score;
    }

    public int getScore() {
        return score;
    }

    @Override
    public String toString() {
        return "Student: #" + hashCode() + ", score: " + score;
    }
}
