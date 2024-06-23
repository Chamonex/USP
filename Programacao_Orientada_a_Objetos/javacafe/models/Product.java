package javacafe.models;

public class Product {
    private final String name;
    private final double price;
    private int amount;
    private double totalPrice;

    public Product(String name, double price) {
        this.name = name;
        this.price = price;
        this.amount = 0;
        this.totalPrice = 0;
    }

    public void addProduct() {
        amount++;
        totalPrice = amount * price;
    }
    public void subProduct() {
        amount--;
        totalPrice = amount * price;
    }

    public double getTotalPrice() {
        return totalPrice;
    }

    public int getAmount() {
        return amount;
    }

}

