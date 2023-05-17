package Teorica.Files;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class FilePrintWrite {
    public static void main(String[] args){

        PrintWriter pw = null;
        try{
            pw = new PrintWriter(new FileWriter(new File("data", "Alunos.txt")));
            String aluno = "Joao Valentia,"+13+","+14.5;
            pw.println(aluno);
            pw.println("Maria Joana,14,12.7");
            pw.println("Pedro Lucas,17,15.4");
        } catch (IOException ioe){
            System.out.println(ioe.toString());
            //ioe.printStackTrace();
        } finally {
            try{
                if(pw!=null){
                    pw.close();
                }
            }catch (Error a){
                throw new RuntimeException();
            }
        }
    }
}
