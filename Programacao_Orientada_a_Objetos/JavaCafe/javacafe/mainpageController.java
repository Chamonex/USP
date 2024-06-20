package javacafe;

import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class mainpageController {
    @FXML
    Label cafeNameLabel;

    public void displaycafe(String cafename){
        cafeNameLabel.setText(cafename);
    }
}
