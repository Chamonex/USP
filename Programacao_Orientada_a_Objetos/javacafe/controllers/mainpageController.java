package javacafe.controllers;

import javacafe.models.Cart;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.IOException;

public class mainpageController {
    private Stage stage;
    private Scene scene;

    Cart cart = new Cart();


    @FXML
    Text numbercapuccino;
    @FXML
    Text numberlatte;
    @FXML
    Text numbermate;
    @FXML
    Text numberespressof;
    @FXML
    Text numberespresso;
    @FXML
    Text numbercookie;
    @FXML
    Text numberbrownie;

    //funcoes de navegacao entre telas
    public void goToOrder(ActionEvent event) throws IOException {
        System.out.print("GO TO ORDER");
        Parent root = FXMLLoader.load(getClass().getResource("../orderpage.fxml"));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }

    public void goToItems(ActionEvent event) throws IOException {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setHeaderText("You are already on the items screen!");
        alert.showAndWait();
    }

    public void goToInventory(ActionEvent event) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("inventorypage.fxml"));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }

    public void goToSales(ActionEvent event) throws IOException {

    }

    public void exitScreen(ActionEvent event) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("firstpage.fxml"));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }

    //funcoes de pedido
    public void takeCapuccino(ActionEvent event) throws IOException {

        if (cart.getItemAmount(0) > 0) {
            System.out.print("cliquei em take capuccino\n");
            cart.editCarrinho(0, 0);
            numbercapuccino.setText(String.valueOf(cart.getItemAmount(0)));
        }
    }

    public void addCapuccino(ActionEvent event) throws IOException {

        System.out.print("cliquei em add capuccino\n");
        cart.editCarrinho(1, 0);
        numbercapuccino.setText(String.valueOf(cart.getItemAmount(0)));

    }

    public void takeLatte(ActionEvent event) throws IOException {
        if (cart.getItemAmount(1) > 0) {

            System.out.print("cliquei em take latte\n");
            cart.editCarrinho(0, 1);
            numberlatte.setText(String.valueOf(cart.getItemAmount(1)));
        }
    }

    public void addLatte(ActionEvent event) throws IOException {
        System.out.print("cliquei em add late\n");
        cart.editCarrinho(1, 1);
        numberlatte.setText(String.valueOf(cart.getItemAmount(1)));
    }

    public void takeMate(ActionEvent event) throws IOException {
        if (cart.getItemAmount(2) > 0) {

            System.out.print("cliquei em take mate\n");
            cart.editCarrinho(0, 2);
            numbermate.setText(String.valueOf(cart.getItemAmount(2)));
        }
    }

    public void addMate(ActionEvent event) throws IOException {
        System.out.print("cliquei em add mate\n");
        cart.editCarrinho(1, 2);
        numbermate.setText(String.valueOf(cart.getItemAmount(2)));
    }

    public void takeEspressoF(ActionEvent event) throws IOException {
        if (cart.getItemAmount(3) > 0) {

            System.out.print("cliquei em take espresso F\n");
            cart.editCarrinho(0, 3);
            numberespressof.setText(String.valueOf(cart.getItemAmount(3)));
        }
    }

    public void addEspressoF(ActionEvent event) throws IOException {
        System.out.print("cliquei em add espresso F");
        cart.editCarrinho(1, 3);
        numberespressof.setText(String.valueOf(cart.getItemAmount(3)));
    }

    public void takeEspresso(ActionEvent event) throws IOException {
        if (cart.getItemAmount(4) > 0) {

            System.out.print("cliquei em take espresso");
            cart.editCarrinho(0, 4);
            numberespresso.setText(String.valueOf(cart.getItemAmount(4)));
        }
    }

    public void addEspresso(ActionEvent event) throws IOException {
        System.out.print("cliquei em add esoressi");
        cart.editCarrinho(1, 4);
        numberespresso.setText(String.valueOf(cart.getItemAmount(4)));
    }

    public void takeCookie(ActionEvent event) throws IOException {
        if (cart.getItemAmount(5) > 0) {

            System.out.print("cliquei em take cookie");
            cart.editCarrinho(0, 5);
            numbercookie.setText(String.valueOf(cart.getItemAmount(5)));
        }
    }

    public void addCookie(ActionEvent event) throws IOException {
        System.out.print("cliquei em add cookie");
        cart.editCarrinho(1, 5);
        numbercookie.setText(String.valueOf(cart.getItemAmount(5)));
    }

    public void takeBrownie(ActionEvent event) throws IOException {
        if (cart.getItemAmount(6) > 0) {

            System.out.print("cliquei em take brownie");
            cart.editCarrinho(0, 6);
            numberbrownie.setText(String.valueOf(cart.getItemAmount(6)));
        }
    }

    public void addBrownie(ActionEvent event) throws IOException {
        System.out.print("cliquei em add brownie");
        cart.editCarrinho(1, 6);
        numberbrownie.setText(String.valueOf(cart.getItemAmount(6)));
    }
}
