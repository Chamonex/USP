package javacafe;

import javacafe.Modules.User;
import javacafe.backend_files.Controller;
import javacafe.backend_files.FileController;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.IOException;

public class newUserController extends Controller {
    private Stage stage;
    private Scene scene;
    private Parent root;

    @FXML
    TextField nameTextField2;
    @FXML
    TextField passwordField2;


    public void createCafe (ActionEvent event) throws IOException {
        FileController fc = new FileController();
        String cafeName = nameTextField2.getText();
        String password = passwordField2.getText();

        User newUser = new User(cafeName, password);
        increment();
        fc.writer(newUser, getnRegisters());


        Parent root = FXMLLoader.load(getClass().getResource("mainpage.fxml"));
        stage = (Stage)((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }

    public void titlescreenNew (ActionEvent event) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("firstpage.fxml"));
        stage = (Stage)((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }
}

