module com.example.lp2_aulas_javafx {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;

    opens edu.ufp.inf.lp2._06_gui_javafx.helloworld to javafx.fxml;
    exports edu.ufp.inf.lp2._06_gui_javafx.helloworld;
}