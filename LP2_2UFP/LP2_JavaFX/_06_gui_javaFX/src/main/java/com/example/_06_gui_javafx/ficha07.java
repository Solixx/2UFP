package com.example._06_gui_javafx;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class ficha07 extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        Button btn= new Button();
        btn.setText("Say Hello World");
        StackPane rootPane= new StackPane();
        rootPane.getChildren().add(btn);
        Scene scene = new Scene(rootPane,400,400);
        primaryStage.setScene(scene);
        primaryStage.show();
        btn.addEventFilter(MouseEvent.MOUSE_CLICKED,(evt)->{
            System.out.println(evt.getEventType()+"Filter Lambda Function btn");
        });
        btn.addEventHandler(MouseEvent.MOUSE_CLICKED,(evt)->{
            System.out.println(evt.getEventType()+"Handler Lambda Function btn");
        });

    }
}
