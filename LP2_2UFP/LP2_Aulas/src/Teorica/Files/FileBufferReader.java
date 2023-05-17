package Teorica.Files;

import edu.princeton.cs.algs4.StdOut;

import java.io.*;
import java.util.StringTokenizer;

public class FileBufferReader {

    public static void main(String [] args){
        try (BufferedReader br = new BufferedReader(new FileReader(new File("data/Alunos.txt")))){
            String line = "";
            int lineCount = 1;
            while ((line = br.readLine()) != null){
                System.out.println("Line" + lineCount + ": " + line);
                String name = "";
                int number = 0;
                float grade = 0.0f;
                StringTokenizer st = new StringTokenizer(line, ",");
                int tokenCount = 0;
                while (st.hasMoreTokens()){
                    String token = st.nextToken();
                    switch (tokenCount){
                        case 0:
                            name = token;
                            break;
                        case 1:
                            number = Integer.parseInt(token.trim());
                            break;
                        case 2:
                            grade = Float.parseFloat(token);
                            break;
                    }
                    tokenCount++;
                }
                System.out.println("Line separated fields " + lineCount + ": " + name + " " + number + " " + grade);
                lineCount++;
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}