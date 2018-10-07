package ru.mirea.khitrov.practice.practice07.task01;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        Player player1 = new Player(reader.readLine()), player2 = new Player(reader.readLine());
        int count = 0;

        while (!player1.lostGame() && !player2.lostGame()) {
            Card c1 = player1.showCard(), c2 = player2.showCard();
            if (c1.canHit(c2)) {
                player1.getNewCards(c1, c2);
            } else {
                player2.getNewCards(c1, c2);
            }
            count++;

            if (count == 106) {
                System.out.println("botva");
                return;
            }
        }
        if (!player1.lostGame()) {
            System.out.println("first " + count);
        } else {
            System.out.println("second " + count);
        }
    }
}
