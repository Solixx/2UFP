module com.example._06_gui_javafx {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.graphics;


    opens com.example._06_gui_javafx to javafx.fxml;
    exports com.example._06_gui_javafx;

    opens com.example._06_gui_javafx.login to javafx.graphics;
    exports com.example._06_gui_javafx.login;

    opens com.example._06_gui_javafx.loginfxml to javafx.fxml;
    exports com.example._06_gui_javafx.loginfxml;

    exports com.example._06_gui_javafx.calc;
    opens com.example._06_gui_javafx.calc to javafx.fxml;

    exports com.example._06_gui_javafx.helloapp;
    opens com.example._06_gui_javafx.helloapp to javafx.fxml;

    exports com.example._06_gui_javafx.bt;
    opens com.example._06_gui_javafx.bt to javafx.fxml;
}