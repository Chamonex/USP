package javacafe;

import javacafe.models.User;
import javacafe.backend_files.LoginController;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.IOException;

public class Scene1controller {

    private Stage stage;
    private Scene scene;
    private Parent root;


    @FXML
    TextField nameTextField;
    @FXML
    TextField passwordField;
    public void newCafe (ActionEvent event) throws IOException {

        Parent root = FXMLLoader.load(getClass().getResource("registerscreen.fxml"));
        stage = (Stage)((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }

    public void logCafe (ActionEvent event) throws IOException {

        Parent root = FXMLLoader.load(getClass().getResource("logscene.fxml"));
        stage = (Stage)((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();

    }

    public void firstPage (ActionEvent event) throws IOException {


        Parent root = FXMLLoader.load(getClass().getResource("firstpage.fxml"));
        stage = (Stage)((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();

    }

    public void login (ActionEvent event) throws IOException {
        LoginController controller = new LoginController();

        String username = nameTextField.getText();
        String pass = passwordField.getText();

        User user = new User(username, pass);
        if(controller.validUser(user)) {
            System.out.print("DEU CERTO");
            Parent root = FXMLLoader.load(getClass().getResource("mainpage.fxml"));
            stage = (Stage)((Node)event.getSource()).getScene().getWindow();
            scene = new Scene(root);
            stage.setScene(scene);
            stage.show();
        }
        else {
            // alert e tentar de novo
            System.out.print("Incorrect username or password");
        }
    }



}
