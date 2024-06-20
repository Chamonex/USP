package javacafe.backend_files;


import javacafe.Modules.User;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

import java.io.IOException;

public class FileController {

    // escrever
    // ler

    private String formatText(User user) {
        String text = "";
        text = text.concat(user.getName());
        text = text.concat("|");
        text = text.concat(user.getPassword());
        text = text.concat("\n");

        return text;

    }

    public void writer(User user, int nRegisters) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter("backend_files/registers.txt", true));
        String text = formatText(user);
        bw.append(text);
        bw.close();

        BufferedWriter vc = new BufferedWriter(new FileWriter("backend_files/variables.txt",false));
        vc.write(nRegisters);
        vc.close();
    }

    static User formatLine(String line) {
        String[] parts = line.split("\\|");
        User user = new User(parts[0], parts[1]);
        return user;
    }

    public User reader(int desiredLine) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("backend_files/registers.txt"));
        String line = br.readLine();
        int i = 0;
        while(line != null) {
            if (desiredLine == i) {
                break;
            }
            i++;
            line = br.readLine();
        }
        assert line != null;
        User user = formatLine(line);
        br.close();
        return user;
    }

    public int getNRegisters() throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("backend_files/variables.txt"));
        int registers = br.read();
        br.close();
        return registers - 48;
    }


}
