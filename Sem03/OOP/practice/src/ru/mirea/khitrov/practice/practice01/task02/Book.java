package ru.mirea.khitrov.practice.practice01.task02;

public class Book {
    private String title;
    private String author;
    private int pagesCount;

    public Book(String title, String author, int pagesCount) {
        this.title = title;
        this.author = author;
        this.pagesCount = pagesCount;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public int getPagesCount() {
        return pagesCount;
    }

    public void setPagesCount(int pagesCount) {
        this.pagesCount = pagesCount;
    }

    @Override
    public String toString() {
        return "Book{" +
                "title='" + title + '\'' +
                ", author='" + author + '\'' +
                ", pages=" + pagesCount +
                '}';
    }
}
