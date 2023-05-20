package com.example._06_gui_javafx.loginfxml;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

/**
 * Use JavaFX FXML (XML-based language) that provides the structure for building a user interface
 * separately from the application code logic.
 *
 * It is possible to create an handler with any language that provides a JSR 223-compatible scripting engine
 * (e.g., JavaScript, Groovy, Jython, and Clojure).
 *
 */
public class LoginFXML extends Application {

    /**
     *
     * @param args
     */
    public static void main(String[] args) {
        launch(args);
    }

    /**
     * This
     * @param primaryStage this is the stage for the GUI
     * @throws IOException
     */
    @Override
    public void start(Stage primaryStage) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("login_fxml0.fxml"));
        //Parent root = FXMLLoader.load(getClass().getResource("login_fxml1.fxml"));
        //Parent root = FXMLLoader.load(getClass().getResource("login_fxml2.fxml"));
        Scene scene = new Scene(root, 300, 300);

        primaryStage.setTitle("FXML Welcome");
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();
    }
}
