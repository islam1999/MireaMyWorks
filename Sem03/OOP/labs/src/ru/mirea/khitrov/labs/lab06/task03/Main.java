package ru.mirea.khitrov.labs.lab06.task03;

import javax.swing.*;
import java.awt.*;

public class Main {
    private static final int fontSize = 15;

    public static void main(String[] args) {
        JTextArea textArea = new JTextArea(10, 25);
        JFrame frame = new JFrame("Text Changer");
        JMenuBar menuBar = new JMenuBar();
        JMenu colorMenu = new JMenu("Color");
        JMenu fontMenu = new JMenu("Font");

        colorMenu.add(createColorChangingItem(textArea, "Blue", Color.BLUE));
        colorMenu.add(createColorChangingItem(textArea, "Red", Color.RED));
        colorMenu.add(createColorChangingItem(textArea, "Black", Color.BLACK));

        fontMenu.add(createFontChangingItem(textArea, "Times New Roman"));
        fontMenu.add(createFontChangingItem(textArea, "MS Sans Serif"));
        fontMenu.add(createFontChangingItem(textArea, "Courier New"));

        menuBar.add(colorMenu);
        menuBar.add(fontMenu);

        frame.add(textArea);

        frame.setSize(500, 300);
        frame.setResizable(false);
        frame.setJMenuBar(menuBar);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private static JMenuItem createFontChangingItem(JTextArea area, String fontName) {
        JMenuItem menuItem = new JMenuItem(fontName);
        menuItem.addActionListener(e -> area.setFont(new Font(fontName, Font.PLAIN, fontSize)));
        return menuItem;
    }

    private static JMenuItem createColorChangingItem(JTextArea area, String cname, Color c) {
        JMenuItem menuItem = new JMenuItem(cname);
        menuItem.addActionListener(e -> area.setForeground(c));
        return menuItem;
    }
}
