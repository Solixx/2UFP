package edu.ufp.inf.lp2._06_gui_javafx.helloworld;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloWorld extends Application {
    @Override
    public void start(Stage primaryStage) throws IOException {
        /*
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 320, 240);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
         */

        Button btn = new Button();
        btn.setText("Say Hello World");

        StackPane rootPane = new StackPane();
        rootPane.getChildren().add(btn);

        Scene scene = new Scene(rootPane, 300, 250);
        primaryStage.setScene(scene);
        primaryStage.show();

        btn.addEventFilter(MouseEvent.MOUSE_CLICKED, (evt) -> {
            System.out.println(evt.getEventType()+" Filter Lambda Function btn");
        });

        btn.addEventHandler(MouseEvent.MOUSE_CLICKED, (evt) ->{
            System.out.println(evt.getEventType()+" Handler Lambda Function btn");
        });

        rootPane.addEventHandler(MouseEvent.MOUSE_CLICKED, (evt) ->{
            System.out.println(evt.getEventType()+" Handler Lambda Function rootPane");
        });
    }

    public static void main(String[] args) {
        launch();
    }
}