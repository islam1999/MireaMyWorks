package ru.mirea.khitrov.practice.practice07.task01;

import java.util.ArrayDeque;
import java.util.ArrayList;

public class Player {
    private ArrayDeque<Card> cards;
    private boolean lostGame = false;

    public Player(String cardsLine) {
        ArrayList<Card> cards = new ArrayList<>();
        for (String s: cardsLine.split(" ")) {
            cards.add(new Card(Integer.parseInt(s)));
        }

        this.cards = new ArrayDeque<>();
        this.cards.addAll(cards);
    }

    public Card showCard() {
        if (cards.size() == 1) {
            lostGame = true;
        }

        return cards.pop();
    }

    public void getNewCards(Card c1, Card c2) {
        cards.add(c1);
        cards.add(c2);
    }

    public boolean lostGame() {
        return this.lostGame;
    }
}
