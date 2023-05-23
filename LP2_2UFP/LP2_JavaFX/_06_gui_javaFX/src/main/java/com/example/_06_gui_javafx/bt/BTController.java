package com.example._06_gui_javafx.bt;

import javafx.beans.property.SimpleStringProperty;
import javafx.collections.ListChangeListener;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.cell.TextFieldTableCell;
import javafx.util.converter.IntegerStringConverter;

import java.io.*;
import java.net.URL;
import java.util.ArrayList;
import java.util.Date;
import java.util.ListIterator;
import java.util.ResourceBundle;
import java.util.*;


public class BTController implements Initializable {

    //Constants declaration for PATHS
    // NB: when running inside IDE, paths are relative to Project's root directory
    private static final String PATH_VEHICLES="./data/vehicles.txt";
    private static final String FILE_DELIMITER=";";
    private static final String PATH_BIN="./data/data_bt.bin";

    //Attributes linking to bt.fxml UI components
    @FXML
    public TableView<Vehicle> vehiclesTable;
    public TableColumn<Vehicle, String> registrationCol;
    public TableColumn<Vehicle, String> brandCol;
    public TableColumn<Vehicle, String> modelCol;
    public TableColumn<Vehicle, Integer> cylindersCol;
    public TextField registrationField;
    public TextField brandField;
    public TextField modelField;
    public TextField cylindersField;
    public ComboBox<String> vehicleComboBox;
    public ComboBox<String> driversComboBox;
    public TableView<PenaltyFee> penaltiesTable;
    public TableColumn<PenaltyFee, String> driverCol;
    public TableColumn<PenaltyFee, String> vehicleCol;
    public TableColumn<PenaltyFee, Date> dateCol;
    public TableColumn<PenaltyFee, String> localCol;
    public TableColumn<PenaltyFee, String> motiveCol;

    private final TransitPolice transitePolice = new TransitPolice();

    /**
     * Inicialização GUI
     */
    @Override
    public void initialize(URL location, ResourceBundle resources) {
        registrationCol.setCellValueFactory(new PropertyValueFactory<Vehicle, String>("registration"));
        registrationCol.setCellFactory(TextFieldTableCell.forTableColumn());

        brandCol.setCellValueFactory(new PropertyValueFactory<Vehicle, String>("brand"));
        brandCol.setCellFactory(TextFieldTableCell.forTableColumn());

        modelCol.setCellValueFactory(new PropertyValueFactory<Vehicle, String>("model"));
        modelCol.setCellFactory(TextFieldTableCell.forTableColumn());

        cylindersCol.setCellValueFactory(new PropertyValueFactory<Vehicle, Integer>("cylinders"));
        cylindersCol.setCellFactory(TextFieldTableCell.forTableColumn(new IntegerStringConverter()));
        /*
        cylindersCol.setCellFactory(new Callback<TableColumn<Vehicle, Integer>, TableCell<Vehicle, Integer>>() {
            @Override
            public TableCell<Vehicle, Integer> call(TableColumn<Vehicle, Integer> col) {
                return new TableCell<Vehicle, Integer>() {
                    @Override
                    protected void updateItem(Integer cylinders, boolean empty) {
                        super.updateItem(cylinders, empty);
                        if (empty) {
                            setText(null);
                        } else {
                            setText(Integer.toString(cylinders));
                        }
                    }
                };
            }
        });
        */

        /*
        vehicleCol.setCellValueFactory(new Callback<TableColumn.CellDataFeatures<PenaltyFee, String>, ObservableValue<String>>() {
            @Override
            public ObservableValue<String> call(TableColumn.CellDataFeatures<PenaltyFee, String> cellDataFeatures) {
                if (cellDataFeatures.getValue() != null) {
                    return new SimpleStringProperty(cellDataFeatures.getValue().getDriver().getName() + " - " + cellDataFeatures.getValue().getDriver().getDriversLicense());
                } else {
                    return new SimpleStringProperty("<No Info>");
                }
            }
        });
        */
        vehicleCol.setCellValueFactory((cellData) -> {
            if (cellData.getValue() != null) {
                return new SimpleStringProperty(cellData.getValue().getDriver().getName() + " - " + cellData.getValue().getDriver().getDriversLicense());
            } else {
                return new SimpleStringProperty("<No Info>");
            }
        });

        vehiclesTable.getItems().addListener( (ListChangeListener<? super Vehicle>)vehiclesChanges -> {
            System.out.println("ListChangeListener - vehiclesChanges = " + vehiclesChanges);
            ObservableList<? extends Vehicle> list = vehiclesChanges.getList();
            list.forEach( vehicle  -> {
                System.out.println("added "+vehicle);
            });
        });
    }

    /**
     * Handler para acção do botão de abertura do ficheiro de texto, referente aos dados dos veículos.
     *
     * @param actionEvent
     */
    public void handleReadTxtFileAction(ActionEvent actionEvent) {
        ArrayList<Vehicle> vehicleArrayList = readVehiclesFromTxtFile(PATH_VEHICLES);
        //TODO...
        //Clear and add all vehicles to vehiclesTable
        this.vehiclesTable.getItems().clear();
        this.vehiclesTable.getItems().addAll(vehicleArrayList);
        //Update ComboBox

        this.vehicleComboBox.getItems().clear();
        this.vehicleComboBox.getItems().addAll(String.valueOf(vehicleArrayList));
    }

    /**
     * Handler para leitura de dados dos veículos a partir de um ficheiro de texto.
     *
     * @return ArrayList<Vehicle>
     * @throws IOException
     */
    private static ArrayList<Vehicle> readVehiclesFromTxtFile(String path) {
        ArrayList<Vehicle> vehicleArrayList = new ArrayList<>();
        BufferedReader br = null;
        try {
            //Open input stream
            br = new BufferedReader(new FileReader(path));
            //TODO...
            String line = "";
            while ((line = br.readLine()) != null){
                String registration = "";
                String brand = "";
                String model = "";
                int cilinders = 0;
                StringTokenizer ST = new StringTokenizer(line, ",");
                int tokenCount = 0;
                while (ST.hasMoreTokens()){
                    String token = ST.nextToken();
                    switch (tokenCount){
                        case 0:
                            registration = token;
                            break;
                        case 1:
                            brand = token;
                            break;
                        case 2:
                            model = token;
                            break;
                        case 3:
                            cilinders = Integer.parseInt(token.trim());
                            break;
                    }
                    tokenCount++;
                }
                Vehicle v = new Vehicle(registration, brand, model, cilinders, new ArrayList<PenaltyFee>());
                vehicleArrayList.add(v);
                //System.out.println("Line separated fields " + registration + ": " + brand + " " + model + " " + cilinders);
            }

        } catch (IOException ioe) {
            System.out.println(ioe);
        } finally {
            if (br!=null) {
                try {
                    br.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        return vehicleArrayList;
    }

    /**
     * Método para inserção de novos veículos na vehicleComboBox (tab Penalties).
     *
     * @param vehicles
     */
    private void addVehiclesToComboBox(ArrayList<Vehicle> vehicles) {
        vehicleComboBox.getItems().clear();
        //TODO...
        this.vehicleComboBox.getItems().addAll(String.valueOf(vehicles));
    }

    /**
     * Handler para acção do botão de armazenamento de dados dos veículos num ficheiro de texto.
     *
     * @param actionEvent
     */
    public void handleSaveTxtFileAction(ActionEvent actionEvent) {
        saveVehiclesToTxtFile(PATH_VEHICLES, vehiclesTable.getItems().listIterator());
    }

    /**
     * Método para efectuar o armazenamento dos dados dos veículos num ficheiro de texto.
     */
    private static void saveVehiclesToTxtFile(String path, ListIterator<Vehicle> listIt) {
        System.out.println("saveVehiclesToTxtFile(): save vehicles to txt...");
        //Try with resources...
        try (PrintWriter pw=new PrintWriter(new FileWriter(path))) {
            //TODO..
            //Save header of file
            pw.println("Registration\tBrand\tModel\tCilinders\tPenaltys");
            //Iterate over listIt and save vehicles into file
            while (listIt.hasNext()){
                Vehicle v = listIt.next();
                String st = v.getRegistration()+","+v.getBrand()+","+v.getModel()+","+v.getCilinders()+","+ v.getPenaltys();
                //pw.println(v.toString());
                pw.println(st);
            }

        } catch (IOException ioe) {
            System.out.println(ioe);
        }
    }

    /**
     * Handler para acção do botão de encerramento da aplicação.
     *
     * @param actionEvent
     */
    public void handleExitAction(ActionEvent actionEvent) {
        System.exit(0);
    }

    /**
     * Handler para acção do botão Add, responsável pela inserção de um veiculo na vehiclesTable.
     *
     * @param actionEvent
     */
    public void handleAddVehicleAction(ActionEvent actionEvent) {
        //TODO...
        //Get vehicle info from GUI TextFields
        String registration = this.registrationField.getText();
        String brand = this.brandField.getText();
        String model = this.modelField.getText();
        String cilinders = this.cylindersField.getText();

        // Instantiate new vehicle

        Vehicle v = new Vehicle(registration, brand, model, Integer.parseInt(cilinders), new ArrayList<>());

        //Add vehicle to table row

        this.vehiclesTable.getItems().add(v);

        //Create ArrayList from all vehicles inside vehiclesTable

        ArrayList<Vehicle> arrVei = new ArrayList<>(this.vehiclesTable.getItems());

        //Add all vehicles to GUI ComboBox

        this.vehicleComboBox.getItems().clear();
        this.vehicleComboBox.getItems().addAll(String.valueOf(arrVei));

        //Clear GUI TextFields
        registrationField.setText("");
        brandField.setText("");
        modelField.setText("");
        cylindersField.setText("");
    }

    /**
     * Handler para acção do botão de abertura do ficheiro binário, referente aos dados dos veículos.
     *
     * @param actionEvent
     */
    public void handleReadBinFileAction(ActionEvent actionEvent) {
        ArrayList<Vehicle> vehicleArrayList = readFromBinFile(PATH_BIN);
        //TODO...
        //Clear vehiclesTable and add vehicles read from file
        this.vehiclesTable.getItems().clear();
        this.vehiclesTable.getItems().addAll(vehicleArrayList);
        //Update ComboBox
        this.vehicleComboBox.getItems().addAll(String.valueOf(vehicleArrayList));
    }

    /**
     * Método para leitura do ficheiro binário, no path indicado.
     */
    private static ArrayList<Vehicle> readFromBinFile(String path) {
        ArrayList<Vehicle> vehicleArrayList = null;
        ObjectInputStream ois=null;
        try {
            //Open input stream
            ois = new ObjectInputStream(new FileInputStream(new File(path)));
            //TODO...
            //Read and cast ArrayList of vehicles from file

            while (ois.available() != 0){
                String registration = (String) ois.readObject();
                String brand = (String) ois.readObject();
                String model = (String) ois.readObject();
                int ciliders = (int) ois.readObject();
                ArrayList<PenaltyFee> PF = new ArrayList<>();
                PF.add((PenaltyFee) ois.readObject());

                Vehicle v = new Vehicle(registration, brand, model, ciliders, PF);

                vehicleArrayList.add(v);
            }


        } catch (IOException e) {
            System.out.println(e);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        } finally {
            if (ois != null) {
                try {
                    ois.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        return vehicleArrayList;
    }

    /**
     * Handler para acção do botão de armazenamento de dados dos veículos num ficheiro binário.
     *
     * @param actionEvent
     */
    public void handleSaveBinFileAction(ActionEvent actionEvent) {
        saveToBinFile(PATH_BIN, this.vehiclesTable.getItems().listIterator());
    }

    /**
     * Método para efectuar o armazenamento dos dados dos veículos num ficheiro binário.
     */
    private static void saveToBinFile(String path, ListIterator<Vehicle> listIt) {
        ObjectOutputStream oos=null;
        try {
            //Open output stream
            oos=new ObjectOutputStream(new FileOutputStream(new File(path)));
            //TODO...
            //Create ArrayList with all vehicles
            ArrayList<Vehicle> arrV = new ArrayList<>();
            while (listIt.hasNext()){
                arrV.add(listIt.next());
            }

            //Save to file
            for (int i = 0; i < arrV.size(); i++){
                Vehicle v = arrV.get(i);
                oos.writeObject(v);
            }

        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (oos != null) {
                try {
                    oos.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    /**
     * Handler para acção de edição dos dados dos veículos na vehiclesTable.
     *
     * @param vehicleStringCellEditEvent
     */
    public void handleEditVehicleAction(TableColumn.CellEditEvent<Vehicle, Object> vehicleStringCellEditEvent) {
        int col=vehicleStringCellEditEvent.getTablePosition().getColumn();
        switch (col) {
            case 0:
                vehicleStringCellEditEvent.getRowValue().setRegistration((String) vehicleStringCellEditEvent.getNewValue());
                break;
            case 1:
                vehicleStringCellEditEvent.getRowValue().setBrand((String) vehicleStringCellEditEvent.getNewValue());
                break;
            case 2:
                vehicleStringCellEditEvent.getRowValue().setModel((String) vehicleStringCellEditEvent.getNewValue());
                break;
            case 3:
                //vehicleStringCellEditEvent.getRowValue().setCylinders(Integer.parseInt(vehicleStringCellEditEvent.getNewValue()));
                vehicleStringCellEditEvent.getRowValue().setCylinders((Integer) vehicleStringCellEditEvent.getNewValue());
                break;
        }
    }

    /**
     * Handler para acção de selecção do veículo na vehicleComboBox (tab Penalties).
     * Pesquisa se veículo seleccionado tem alguma multa inserida pela brigada de trânsito
     *
     * @param actionEvent
     */
    public void handleSelectVehicleAction(ActionEvent actionEvent) {
        penaltiesTable.getItems().clear();
        String vRegistration=vehicleComboBox.getValue();
        try {
            Vehicle v = transitePolice.searchVehicle(vRegistration);
            if (v != null) {
                penaltiesTable.getItems().addAll(transitePolice.allPenaltyFeesbyVehicle(v));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Handler para acção de selecção dos condutores na driversComboBox (tab Penalties).
     *
     * @param actionEvent
     */
    public void handleSelectDriverAction(ActionEvent actionEvent) {
        System.out.println("Not implemented yet! :(");
    }

    public TableView<Vehicle> getVehiclesTable() {
        return vehiclesTable;
    }

    public void setVehiclesTable(TableView<Vehicle> vehiclesTable) {
        this.vehiclesTable = vehiclesTable;
    }

    public TableColumn<Vehicle, String> getRegistrationCol() {
        return registrationCol;
    }

    public void setRegistrationCol(TableColumn<Vehicle, String> registrationCol) {
        this.registrationCol = registrationCol;
    }

    public TableColumn<Vehicle, String> getBrandCol() {
        return brandCol;
    }

    public void setBrandCol(TableColumn<Vehicle, String> brandCol) {
        this.brandCol = brandCol;
    }

    public TableColumn<Vehicle, String> getModelCol() {
        return modelCol;
    }

    public void setModelCol(TableColumn<Vehicle, String> modelCol) {
        this.modelCol = modelCol;
    }

    public TableColumn<Vehicle, Integer> getCylindersCol() {
        return cylindersCol;
    }

    public void setCylindersCol(TableColumn<Vehicle, Integer> cylindersCol) {
        this.cylindersCol = cylindersCol;
    }

    public TextField getRegistrationField() {
        return registrationField;
    }

    public void setRegistrationField(TextField registrationField) {
        this.registrationField = registrationField;
    }

    public TextField getBrandField() {
        return brandField;
    }

    public void setBrandField(TextField brandField) {
        this.brandField = brandField;
    }

    public TextField getModelField() {
        return modelField;
    }

    public void setModelField(TextField modelField) {
        this.modelField = modelField;
    }

    public TextField getCylindersField() {
        return cylindersField;
    }

    public void setCylindersField(TextField cylindersField) {
        this.cylindersField = cylindersField;
    }

    public ComboBox<String> getVehicleComboBox() {
        return vehicleComboBox;
    }

    public void setVehicleComboBox(ComboBox<String> vehicleComboBox) {
        this.vehicleComboBox = vehicleComboBox;
    }

    public ComboBox<String> getDriversComboBox() {
        return driversComboBox;
    }

    public void setDriversComboBox(ComboBox<String> driversComboBox) {
        this.driversComboBox = driversComboBox;
    }

    public TableView<PenaltyFee> getPenaltiesTable() {
        return penaltiesTable;
    }

    public void setPenaltiesTable(TableView<PenaltyFee> penaltiesTable) {
        this.penaltiesTable = penaltiesTable;
    }

    public TableColumn<PenaltyFee, String> getDriverCol() {
        return driverCol;
    }

    public void setDriverCol(TableColumn<PenaltyFee, String> driverCol) {
        this.driverCol = driverCol;
    }

    public TableColumn<PenaltyFee, String> getVehicleCol() {
        return vehicleCol;
    }

    public void setVehicleCol(TableColumn<PenaltyFee, String> vehicleCol) {
        this.vehicleCol = vehicleCol;
    }

    public TableColumn<PenaltyFee, Date> getDateCol() {
        return dateCol;
    }

    public void setDateCol(TableColumn<PenaltyFee, Date> dateCol) {
        this.dateCol = dateCol;
    }

    public TableColumn<PenaltyFee, String> getLocalCol() {
        return localCol;
    }

    public void setLocalCol(TableColumn<PenaltyFee, String> localCol) {
        this.localCol = localCol;
    }

    public TableColumn<PenaltyFee, String> getMotiveCol() {
        return motiveCol;
    }

    public void setMotiveCol(TableColumn<PenaltyFee, String> motiveCol) {
        this.motiveCol = motiveCol;
    }

    public TransitPolice getTransitePolice() {
        return transitePolice;
    }

    public void handleReadFileAction(ActionEvent actionEvent) {
    }

    public void handleSaveFileAction(ActionEvent actionEvent) {
    }
}
