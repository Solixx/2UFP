package com.example._06_gui_javafx.loginfxml;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;


/**
 * Use the FXML Controller to make the Text control display a message when the user presses the button.
 *
 */
public class LoginFXMLController {

    /**
     * For the controller to be able to access the Text label, its name should be the same in the fxml and css
     */
    @FXML
    private Text textActionTarget;
    @FXML
    private TextField usernameField;
    @FXML
    private PasswordField passwordField;

    /**
     *
     * @param event
     */
    @FXML
    protected void handleSubmitButtonAction(ActionEvent event) {
        textActionTarget.setText("Sign in button calling Controller->handleSubmitButtonAction()");
    }

    /**
     *
     * @param event
     */
    @FXML
    protected void handleSubmitButtonAction2(ActionEvent event) {
        textActionTarget.setText("Sign in button calling Controller->handleSubmitButtonAction2()");
    }
}
