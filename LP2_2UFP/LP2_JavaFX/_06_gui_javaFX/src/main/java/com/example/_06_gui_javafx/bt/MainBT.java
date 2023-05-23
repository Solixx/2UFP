package com.example._06_gui_javafx.bt;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class MainBT extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws IOException {
        Parent root = FXMLLoader.load(getClass().getResource("bt.fxml"));
        Scene scene = new Scene(root);

        primaryStage.setTitle("Transit Police");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}
