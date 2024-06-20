package javacafe.backend_files;

import java.io.IOException;

public class Controller {
    static int nRegisters;

    static int initnRegisters() {
        try {
            FileController fc = new FileController();
            int n = fc.getNRegisters();
            return n;
        }
        catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public Controller() {
        nRegisters = initnRegisters();
    }

    public static void increment() {
        nRegisters++;
    }

    public static int getnRegisters() {
        return nRegisters;
    }
}
