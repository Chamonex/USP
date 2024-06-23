package javacafe.backend_files;

import javacafe.models.User;

import java.io.IOException;

public class LoginController extends Controller{


    public boolean validUser(User user) throws IOException {
        FileController fc = new FileController();
        int n = fc.getNRegisters();

        for (int i = 0; i < n; i++) {
            User u = fc.reader(i);
            if ((u.getName().equals(user.getName())) && (u.getPassword().equals(user.getPassword()))) {
                return true;
            }
        }


        return false;
    }


}