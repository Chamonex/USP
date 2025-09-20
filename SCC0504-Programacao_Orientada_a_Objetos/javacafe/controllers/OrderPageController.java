package javacafe.controllers;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.text.Text;

import java.io.IOException;

public class OrderPageController {

    @FXML
    private Text orderText;

    public void finishOrder(ActionEvent event) throws IOException {
        System.out.print("CLIQUEI EM FINISH ORDER");
        orderText.setText("MUDEI");
    }

}
