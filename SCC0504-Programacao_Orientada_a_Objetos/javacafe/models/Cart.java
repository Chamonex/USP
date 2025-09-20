package javacafe.models;

public class Cart {

    private final Product[] lista;
    double totalPrice;

    public Cart() {
        Product[] list = new Product[7];
        list[0] = new Product("Capuccino", 10.9);
        list[1] = new Product("Latte", 6.9);
        list[2] = new Product("Mate", 8.9);
        list[3] = new Product("Espresso", 4.9);
        list[4] = new Product("Espresso Extraforte", 5.9);
        list[5] = new Product("Cookie", 10.9);
        list[6] = new Product("Brownie", 10.9);

        lista = list;
        totalPrice = 0;
    }

    public void editCarrinho(int opt, int n) {
        if (opt == 1) {
            lista[n].addProduct();
        }
        else if (opt == 0) {
            lista[n].subProduct();
        }
    }

    public int getItemAmount(int n) {
        return lista[n].getAmount();
    }


}


